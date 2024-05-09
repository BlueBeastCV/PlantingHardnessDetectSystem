#opencv3.4.1
OPENCV_DIR = $$PWD/opencv_sdk/opencv-3.4.1
OPENCV_LIB_DIR = $${OPENCV_DIR}/x64/vc14/lib
CV_VER = 341
CV_LIB_NAMES = world


#opencv2.4.13
#OPENCV_DIR = $$PWD/opencv_sdk/opencv-2.4.13
#OPENCV_LIB_DIR = $${OPENCV_DIR}/x64/vc12/lib
#CV_VER = 2413
##CV_LIB_NAMES = core imgproc highgui calib3d
#CV_LIB_NAMES = core imgproc highgui video videostab calib3d contrib features2d flann legacy nonfree objdetect ocl photo stitching


for(lib, CV_LIB_NAMES){
	CV_LIBS +=-lopencv_$$lib
}
CONFIG(release, debug|release){
	CV_LIB_PREFIX =$$CV_VER
}
else{
	CV_LIB_PREFIX = $${CV_VER}d
	CONFIG +=console
}
for(lib,CV_LIBS){
	CV_LIBS_NEW += $$lib$$CV_LIB_PREFIX
}

CV_LIBS = $$CV_LIBS_NEW $$CV_EXT_LIBS
LIBS += -L$$OPENCV_LIB_DIR $$CV_LIBS
INCLUDEPATH += $$OPENCV_DIR/include




