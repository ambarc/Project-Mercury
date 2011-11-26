SET(ClipperSource "${PROJECT_SOURCE_DIR}/src/Video/VideoLowLevel/PMVideoClipper.cxx" 
"${PROJECT_SOURCE_DIR}/src/Application/PMVideoClipperUseCase.cxx")
ADD_EXECUTABLE(VideoClipperUseCase ${ClipperSource})
TARGET_LINK_LIBRARIES(VideoClipperUseCase ${OpenCV_LIBS})

SET(MasherSource "${PROJECT_SOURCE_DIR}/src/Video/VideoLowLevel/PMVideoMasher.cxx" 
"${PROJECT_SOURCE_DIR}/src/Application/PMVideoMasherUseCase.cxx")
ADD_EXECUTABLE(VideoMasherUseCase ${MasherSource})
TARGET_LINK_LIBRARIES(VideoMasherUseCase ${OpenCV_LIBS})

SET(VideoLowLevelManagerSource "${PROJECT_SOURCE_DIR}/src/Video/VideoLowLevel/PMVideoMasher.cxx"
"${PROJECT_SOURCE_DIR}/src/Video/VideoLowLevel/PMVideoClipper.cxx"
"${PROJECT_SOURCE_DIR}/src/Video/VideoMidLevel/PMVideoLowLevelManager.cxx"
"${PROJECT_SOURCE_DIR}/src/Application/PMVideoLowLevelManagerUseCase.cxx")
ADD_EXECUTABLE(VideoLowLevelManagerUseCase ${VideoLowLevelManagerSource})
TARGET_LINK_LIBRARIES(VideoLowLevelManagerUseCase ${OpenCV_LIBS})