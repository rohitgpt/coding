import csv
import numpy as np
import pandas as pd
from dateutil import parser as dt_parse
from datetime import datetime

import keras
from keras.models import Sequential
from keras.layers import Dense, Dropout

from sklearn.metrics import accuracy_score
# from sklearn.linear_model import LogisticRegression
# from sklearn.svm import LinearSVC
from sklearn.svm import SVR
from sklearn.kernel_ridge import KernelRidge
from sklearn.neural_network import MLPRegressor


data = pd.read_csv("train.csv")
test_data = pd.read_csv("test.csv")

city = data.From.unique().tolist()
flight_class = data.Class.unique().tolist() 

current_datetime = datetime.now()


'''Function to generate the feature vectors'''
def create_feature_vec(row, ind, city, flight_class):
	## one-hot encoded feature for source & destination
	city_vec = np.zeros(len(city))
	city_vec[city.index(row['From'])] = 2
	city_vec[city.index(row['To'])] = 1

	## one-hot encoded feature for different age groups
	## Age category:
	# [0-12): C1
	# [12, 25): C2
	# [25, 60): C3
	# 60+: C4
	age_vec = np.zeros(4)
	age = ((dt_parse.parse(row['Booking Date']) - dt_parse.parse(row['Date of Birth'])).days)/365
	if age < 12:
		age_vec[0] = 1
	elif age < 25:
		age_vec[1] = 1
	elif age < 60:
		age_vec[2] = 1
	else:
		age_vec[3] = 1

	# duration: No. of days left for the flight journey
	duration = (dt_parse.parse(row['Flight Date']) - dt_parse.parse(row['Booking Date'])).days

	# feature for the day of the week when flight journey begin: [Week day index, Flag for weekend]
	# week day index: {S: 0, Sat: 1, F: 2, Th: 3, W: 4, T: 5, M: 6} 
	# NOTE: current day of Challenge is Sunday
	weekday_vec = np.zeros(2)
	weekday_ind = ((current_datetime - dt_parse.parse(row['Flight Date'])).days)%7
	weekday_vec[0] = weekday_ind
	if weekday_ind <=1:
		weekday_vec[1] = 1

	# feature for the flight time in minutes
	time = dt_parse.parse(row['Flight Time'])
	flight_time = time.hour*60+time.minute+time.second/60

	# one-hot encoded faeture for the flight class
	flight_class_vec = np.zeros(len(flight_class))
	flight_class_vec[flight_class.index(row['Class'])] = 1

	# concatenated feature vector
	feature_vec = np.concatenate((np.asarray([age]), np.concatenate((city_vec, flight_class_vec))))
	# feature_vec = np.concatenate((age_vec, np.concatenate((city_vec, flight_class_vec))))
	# feature_vec = np.concatenate((city_vec, flight_class_vec))
	feature_vec = np.concatenate((np.concatenate((feature_vec, weekday_vec)), np.asarray([duration, flight_time])))

	return feature_vec


'''Fares series analysis overall and categorically (source-destination)'''
## overall mean, standard deviation, minimum and maximum values of the training data
global_mean = data.Fare.mean()
global_std = data.Fare.std()
global_min = data.Fare.min()
global_max = data.Fare.max()

## categorically finding the mean, standard deviation, minimum and maximum value for different source-destination 
## journey from the training data
mean = np.zeros((len(city), len(city)))
std_dev = np.zeros((len(city), len(city)))
minimum = np.zeros((len(city), len(city)))
maximum = np.zeros((len(city), len(city)))
for source in city:
	for destination in city:
		fares = data.Fare[(data['From'] == source) & (data['To'] == destination)]
		mean[city.index(source)][city.index(destination)] = fares.mean()
		std_dev[city.index(source)][city.index(destination)] = fares.std()
		minimum[city.index(source)][city.index(destination)] = fares.min()
		maximum[city.index(source)][city.index(destination)] = fares.max()


'''Generating the feature vectors, X and normalized fares, Y from the training data'''
X_train = []
Y_train = []
for ind,row in data.iterrows():
	feature_vec = create_feature_vec(row, ind, city, flight_class)

	## Normalise the fares using either min-max method (feature scaling) or 
	mean_ = mean[city.index(row['From'])][city.index(row['To'])]
	std_ = std_dev[city.index(row['From'])][city.index(row['To'])]
	# norm_fare = (row['Fare'] - mean_)/(8*std_)
	min_ = minimum[city.index(row['From'])][city.index(row['To'])]
	max_ = maximum[city.index(row['From'])][city.index(row['To'])]
	norm_fare = (row['Fare'] - min_)/(max_-min_)
	# norm_fare = (row['Fare'] - global_min)/(global_max - global_min)

	X_train.append(feature_vec)
	Y_train.append(norm_fare)

X_train_mat = np.asarray(X_train)
Y_train_mat = np.asarray(Y_train)	

'''Generate feature vectors from test data'''
X_test = []
for ind,row in test_data.iterrows():
	feature_vec = create_feature_vec(row, ind, city, flight_class)
	X_test.append(feature_vec)
X_test_mat = np.asarray(X_test)


print(len(X_train))
print(len(Y_train))
print(max(Y_train), min(Y_train))


# split the training data for training and testing
split_ind = int(0.95*len(X_train))


## Initializing Neural Network
classifier = Sequential()

# Adding the input layer and the first hidden layer
classifier.add(Dense(output_dim = 32, init = 'uniform', activation = 'relu', input_dim = len(X_train[0])))
# Adding the intermediate hidden layers
classifier.add(Dense(output_dim = 8, init = 'uniform', activation = 'relu'))
classifier.add(Dense(output_dim = 8, init = 'uniform', activation = 'relu'))
# classifier.add(Dense(output_dim = 16, init = 'uniform', activation = 'relu'))
# classifier.add(Dense(output_dim = 16, init = 'uniform', activation = 'relu'))
classifier.add(Dense(output_dim = 4, init = 'uniform', activation = 'relu'))

# classifier.add(Dropout(0.5))
classifier.add(Dense(output_dim = 4, init = 'uniform', activation = 'relu'))
# Adding the output layer
classifier.add(Dense(output_dim = 1, init = 'uniform', activation = 'sigmoid'))

# Compiling Neural Network
classifier.compile(optimizer = 'adam', loss = 'binary_crossentropy', metrics = ['accuracy'])

# Fitting our model 
classifier.fit(X_train_mat[:split_ind], Y_train_mat[:split_ind], batch_size = 100, epochs = 1000)
# Predicting the Test set results
Y_predict = classifier.predict(X_train_mat[split_ind+1:])


# clf=LogisticRegression()
# clf = SVR()
# clf = KernelRidge(alpha=1.0)
# clf = MLPRegressor(hidden_layer_sizes=(128, 16, ))  

# clf.fit(X_train_mat[:split_ind], Y_train_mat[:split_ind])
# Y_predict = clf.predict(X_train_mat[split_ind+1:])
y = []
for i in range(len(Y_predict)):
	if Y_train_mat[split_ind+1+i]==0:
		continue
	y.append(abs(Y_predict[i] - Y_train_mat[split_ind+1+i]/Y_train_mat[split_ind+1+i]))

# y = [abs(Y_predict[i] - Y_train_mat[split_ind+1+i]/Y_train_mat[split_ind+1+i]) for i in range(len(Y_predict))] 
# y = abs(Y_predict - Y_train_mat[split_ind+1:])/Y_train_mat[split_ind+1:] 
print('Learning error_score: ', np.mean(y))


Y = []
Y_test_predict = classifier.predict(X_test_mat)
# i = 0
for ind,row in test_data.iterrows():
	min_ = minimum[city.index(row['From'])][city.index(row['To'])]
	max_ = maximum[city.index(row['From'])][city.index(row['To'])]
	Y.append(Y_test_predict[ind][0]*(max_-min_) + min_)
	# Y.append(Y_test_predict[ind]*(global_max - global_min) + global_min)

print(Y)