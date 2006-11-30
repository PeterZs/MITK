SET(CPP_FILES
  mitkBaseController.cpp
  mitkCameraController.cpp
  mitkCameraRotationController.cpp
  mitkFocusManager.cpp
  mitkLimitedLinearUndo.cpp
  mitkMovieGenerator.cpp
  mitkMultiStepper.cpp
  mitkOperationEvent.cpp
  mitkRenderingManager.cpp
  mitkReportGenerator.cpp
  mitkSliceNavigationController.cpp
  mitkSlicesCoordinator.cpp
  mitkSlicesRotator.cpp
  mitkStatusBar.cpp
  mitkStepper.cpp
  mitkUndoController.cpp
  mitkUndoModel.cpp
  mitkVerboseLimitedLinearUndo.cpp
  mitkVtkInteractorCameraController.cpp
  mitkVtkLayerController.cpp
  # VtkQRenderWindowInteractor.cpp
)
IF(WIN32)
  SET(CONTROLLERS_CPP ${CONTROLLERS_CPP} mitkMovieGeneratorWin32.cpp)
ENDIF(WIN32)
