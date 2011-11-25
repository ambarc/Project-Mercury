SET(ClipperSource "${PROJECT_SOURCE_DIR}/src/Video/VideoLowLevel/PMVideoClipper.cxx" 
"${PROJECT_SOURCE_DIR}/src/Application/PMVideoClipperUseCase.cxx")
ADD_EXECUTABLE(VideoClipperUseCase ${ClipperSource})
TARGET_LINK_LIBRARIES(VideoClipperUseCase ${OpenCV_LIBS})