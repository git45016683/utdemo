currentpath=$(pwd)
cd ..
buildfolder='build'
if [ ! -d "$buildfolder" ]; then
	echo "no----has----build"
	mkdir $buildfolder
fi

cd $buildfolder
rm ./*

qmake $currentpath
make clean;
make -j4

./utdemo

