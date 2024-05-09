#此方法将include和lib文件置于项目路径下，便于项目的完整性，不用自己重新配置sdk
#INCLUDEPATH += $$PWD/vlc-2.2.6-win64/include \

#LIBS += -L"$$PWD/vlc-2.2.6-win64/lib" \
#    -llibvlc \
#    -llibvlccore




#basler相机
#INCLUDEPATH +=  $$PWD/camera_sdk/basler_sdk/include

#LIBS += -L"$$PWD/camera_sdk/basler_sdk/lib/x64" \
#    -lGCBase_MD_VC141_v3_1_Basler_pylon_v5_1 \
#    -lGenApi_MD_VC141_v3_1_Basler_pylon_v5_1 \
#    -lPylonBase_v5_1 \
#    -lPylonC \
#    -lPylonGUI_v5_1 \
#    -lPylonUtility_v5_1

#海康相机
INCLUDEPATH +=  $$PWD/camera_sdk/MVS_sdk/Includes

LIBS += -L"$$PWD/camera_sdk/MVS_sdk/Libraries/win64" \
    -lMvCameraControl

#海康线激光
#INCLUDEPATH +=  $$PWD/camera_sdk/3DMVS_sdk/MvStereoAppSDK/h

#LIBS += -L"$$PWD/camera_sdk/3DMVS_sdk/MvStereoAppSDK/lib/win64" \
#    -lMvStereoAppCtrl


#basler 使用方法 此方法也可行
#LIBS += D:/basler/Development/lib/x64/GCBase_MD_VC141_v3_1_Basler_pylon_v5_1.lib
#LIBS += D:/basler/Development/lib/x64/GenApi_MD_VC141_v3_1_Basler_pylon_v5_1.lib
#LIBS += D:/basler/Development/lib/x64/PylonBase_v5_1.lib

#LIBS += D:/basler/Development/lib/x64/PylonC.lib
#LIBS += D:/basler/Development/lib/x64/PylonGUI_v5_1.lib
#LIBS += D:/basler/Development/lib/x64/PylonUtility_v5_1.lib


#海康威视使用方法 此方法也可行
#INCLUDEPATH +=  D:/MVS_STD_3.3.1_201207/MVS/Development/Includes
#LIBS += D:/MVS_STD_3.3.1_201207/MVS/Development/Libraries/win64/MvCameraControl.lib


