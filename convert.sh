#/bin/sh
ff=basename `PWD`
if [ $# -ge 1 ]
then
	ff=$1
fi
# for ff in $(find $PWD/ -name '*.mkv' -or -name '*.avi' -or -name '*.mp4')
# for ff in $(find $ff/ -name '*.mkv' -or -name '*.avi' -or -name '*.mp4')
for f in $(find $ff -name '*.mkv' -or -name '*.avi' -or -name '*.mp4' -print0)
do
	ffmpeg -i $f -c:v libx265 -preset slow "${f%.*}.mkv" -y
done
