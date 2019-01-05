// File name: [main.cpp] (Copyright to Samil Chai)
// Diagrams:
//		UML: 
//		Use case: https://www.draw.io/?state=%7B%22ids%22:%5B%220B8vIEi2xiwB4NlVaZ1VtNmFnOXc%22%5D,%22action%22:%22open%22,%22userId%22:%22112934744561083886759%22%7D#G0B8vIEi2xiwB4NlVaZ1VtNmFnOXc
//		Sequence diagram: 
// Staff: 
//		Lead programmer: Samil Chai
//		Junior programmer: Nick Jang
// Descriptions & Comments:
// - [Resources]: 
//		Code brought from BraynzarSoft tutorial 09: https://www.braynzarsoft.net/viewtutorial/q16390-transformations-and-world-view-projection-space-matrices
//		Code brought from BraynzarSoft tutorial 11: https://www.braynzarsoft.net/viewtutorial/q16390-11-drawing-text-in-directx-12
//		Code ported originally from WY_PROJ_DIRECTX_12_ver0128
// - [Description]: 
//		Main Win32 program with DirectX 12.
// - [Comments]:
//		Font framework and timer framework added, code mostly brought from
//			BraynzarSoft tutorial 11: https://www.braynzarsoft.net/viewtutorial/q16390-11-drawing-text-in-directx-12
//			Font and timer framework code ported from the tutorial.
//			MyFont class added to wrap up the Font structure provided in the 
//				tutorial or else the main.cpp will have too much lines of code.
//		Testing animation applied onto an armature object, after implementing 
//			following classes:
//			MyModelAnimation class
//			MyModelAnimationBone class
//			MyModelArmature class
//			MyModelArmature class
//		Added animation loading framework and tested.
//		Added animation applying framework and tested.
//		Code description added on top of this file for better 
//			visualization of the codes.
//		Main use case diagram has been added to the main project folder as JPEG
//			image file, it shows the framework order and some detail 
//			explainations on loading models, fonts, armatures and animations.
// - [Backup]: 
//		WY_PROJ_DIRECTX_12_WIN32_ver0037
//------------------------------------------------------------------------------
// [rev0003:WY:201707242300]
//------------------------------------------------------------------------------
// File name: [main.cpp] (Copyright to Samil Chai)
// Diagrams:
//		UML: 
//		Use case: 
//		Sequence diagram: 
// Staff: 
//		Lead programmer: Samil Chai
//		Junior programmer: Nick Jang
// Descriptions & Comments:
// - [Resources]: 
//		Code brought from BraynzarSoft tutorial: https://www.braynzarsoft.net/viewtutorial/q16390-transformations-and-world-view-projection-space-matrices
//		Code ported originally from WY_PROJ_DIRECTX_12_ver0128
// - [Description]: 
//		Main Win32 program with DirectX 12.
// - [Comments]:
//		All the prototypes and -- Global variables has been moved from stdafx.h to
//			on top of this file.
//		Because this caused a lot of linking errors when i tried to include
//			stdafx.h in other class -- Headers
//		Aniamtion loading framework tested in mainInit() function, i can now
//			export an animation with my custom animationExporter.blend through
//			Blender, and load it onto this engine by calling 
//			MyModelLoader::myAnimationLoader() function which returns a loaded
//			animation data on a MyModelAnimation object which holds all the 
//			animation bones with their own animation data stored inside each
//			MyModelAnimationBone object.
// - [Backup]: 
//		WY_PROJ_DIRECTX_12_WIN32_ver0030
//------------------------------------------------------------------------------
// [rev0002:WY:201707182120]
//------------------------------------------------------------------------------
// File name: [main.cpp] (Copyright to Samil Chai)
// Diagrams:
//		UML: 
//		Use case: 
//		Sequence diagram: 
// Staff: 
//		Lead programmer: Samil Chai
//		Junior programmer: Nick Jang
// Descriptions & Comments:
// - [Resources]: 
//		Code brought from BraynzarSoft tutorial: https://www.braynzarsoft.net/viewtutorial/q16390-transformations-and-world-view-projection-space-matrices
//		Code ported originally from WY_PROJ_DIRECTX_12_ver0128
// - [Description]: 
//		Main Win32 program with DirectX 12.
// - [Comments]:
//		SRV need to be initialized as root parameter for texture loading
//			so changing root signature init code with code brought from 
//			WY_PROJ_DIRECTX_12_ver0128
//			
// - [Backup]: 
//		WY_PROJ_DIRECTX_12_WIN32_ver0004
//------------------------------------------------------------------------------
// [rev0001:WY:201706302110]
//------------------------------------------------------------------------------
// File name: [main.cpp] (Copyright to Samil Chai)
// Diagrams:
//		UML: 
//		Use case: 
//		Sequence diagram: 
// Staff: 
//		Lead programmer: Samil Chai
//		Junior programmer: Nick Jang
// Descriptions & Comments:
//	- [Resources]: 
//		Code brought from BraynzarSoft tutorial: https://www.braynzarsoft.net/viewtutorial/q16390-transformations-and-world-view-projection-space-matrices
//		Code ported originally from WY_PROJ_DIRECTX_12_ver0128
//	- [Description]: 
//		Main Win32 program with DirectX 12.
//	- [Backup]: ver0002
//	- [Comments]:
//		void mainInit(); function added to init main Camera object to store all
//			the camera information into one.
//		Caling mainInit() function added to WinMain() function, to init main 
//			Camera object before accessing it.
//		Uncommented unecessary camera related global variable codes and 
//			replaced with main Camera object's get set function code in main 
//			Update() function, to update the camera view and projection 
//			matrices onto each cubes' constant buffers.
//------------------------------------------------------------------------------
// [rev0000:WY:201706272140]
//------------------------------------------------------------------------------
//##############################################################################
//##############################################################################
//##############################################################################
// Code
//##############################################################################
//##############################################################################
//##############################################################################
#pragma once

//##############################################################################
// Code description: 
//	(Can search the code with following keywords)
//##############################################################################
// -- Headers
// -- Global variables
// -- Global variables - Do not touch zone
// -- Global variables - Can touch zone
// -- Global variables - CBV related
// -- Global variables - Resource objects
// -- Global variables - Testing classes
// -- Function prototypes
//
// -- Main function
	// -- Initialize resources objects (Models, fonts, animations ... )
	// -- Create the window
	// -- Initialize direct3d
		// -- Create the device (Graphic card, adpater)
		// -- Create a direct command queue
		// -- Create the swap Chain (double/tripple buffering)
		// -- Create the back Buffers (render target views RTV) Descriptor Heap
		// -- Create the command Allocators
		// -- Create a command List
		// -- Create root signature
		// -- Create vertex and pixel shaders for main PSO
		// -- Create input layout for main PSO
		// -- Create main pipeline state object (PSO)
		// -- Create vertex and pixel shaders for text PSO
		// -- Create input layout for text PSO
		// -- Create the depth/stencil buffer
		// -- Create the descriptor heap that will store our SRV
		// -- Fill out the viewport
		// -- Fill out a scissor rect
			// -- Init SRV handles (CPU, GPU)
			// -- Init fonts (MyFont)
			// -- Init models (MySpecialModelObjMtl)
		// -- Create the constant buffer resource heap
			// -- Models constant buffer init (MySpecialModelObjMtl)
	// -- Start the main loop
		// -- Main update function (Update())
		// -- Main render function executes the command list. (Render())
			// -- Main update pipeline function (UpdatePipeLine())
				// -- Render models
				// -- Render fonts 
	// We want to wait for the gpu to finish executing the command list 
	// before we start releasing everything.
	// -- Close the fence event
	// -- Clean up everything
//##############################################################################


//##############################################################################
// -- Headers
//##############################################################################
#include "stdafx.h"
#include "Camera.h"
#include "MyFont.h"

//##############################################################################
// -- Global variables
//##############################################################################
//==============================================================================
// -- Global variables - Do not touch zone
//==============================================================================
// This will only call release if an object exists 
// (prevents exceptions calling release on non existant objects).
#define SAFE_RELEASE(p) { if ( (p) ) { (p)->Release(); (p) = 0; } }

// Handle to the window.
HWND hwnd = NULL;

// Name of the window (not the title).
LPCTSTR WindowName = L"WY_PROJ_DIRECTX_12_WIN32";

// title of the window.
LPCTSTR WindowTitle = L"WY_PROJ_DIRECTX_12_WIN32 Window";

// Width and height of the window.
int Width = 800;
int Height = 600;

// is window full screen?
bool FullScreen = false;

// We will exit the program when this becomes false.
bool Running = true;

ID3D12Device *device; // Direct3d device.
IDXGISwapChain3 *swapChain; // Swapchain used to switch between render targets.
ID3D12CommandQueue *commandQueue; // Container for command lists.
// A descriptor heap to hold resources like the render targets.
ID3D12DescriptorHeap *rtvDescriptorHeap; 
// Number of render targets equal to buffer count.
ID3D12Resource *renderTargets[frameBufferCount]; 
// We want enough allocators for each 
// buffer  *number of threads (we only have one thread).
ID3D12CommandAllocator *commandAllocator[frameBufferCount]; 

// A command list we can record commands into,
// then execute them to render the frame.
ID3D12GraphicsCommandList *commandList; 

// An object that is locked while our command list is being executed by the gpu. 
// We need as many as we have allocators (more if we want to know when the 
// gpu is finished with an asset).
ID3D12Fence *fence[frameBufferCount];    

// A handle to an event when our fence is unlocked by the gpu.
HANDLE fenceEvent; 

// This value is incremented each frame. each fence will have its own value.
UINT64 fenceValue[frameBufferCount]; 

// Current rtv we are on
int frameIndex; 

// Size of the rtv descriptor on the device 
// (all front and back buffers will be the same size).
int rtvDescriptorSize; 

//==============================================================================
// -- Global variables - Can touch zone
//==============================================================================
// Main PSO - PSO containing a pipeline state.
ID3D12PipelineState *pipelineStateObject;
// Text PSO - PSO containing a pipeline state for font rendering
ID3D12PipelineState* textPSO;

// Main root signature - Root signature defines data shaders will access.
ID3D12RootSignature *rootSignature;

// Area that output from rasterizer will be stretched to.
D3D12_VIEWPORT viewport;
// The area to draw in. pixels outside that area will not be drawn onto.
D3D12_RECT scissorRect;

// This is the memory for our depth buffer.
ID3D12Resource *depthStencilBuffer;
// This is a heap for our depth/stencil buffer descriptor.
ID3D12DescriptorHeap *dsDescriptorHeap;

// This is a heap for our SRV texture buffer descriptor.
ID3D12DescriptorHeap *srvDescriptorHeap;

//==============================================================================
// -- Global variables - CBV related
//==============================================================================
// This is the constant buffer data we will be use to send the CBV to the gpu 
ModelViewProjectionConstantBuffer cbPerObject;
// This is the memory on the gpu where constant buffers for each frame
// will be placed.
ID3D12Resource *constantBufferUploadHeaps[frameBufferCount];
// This is a pointer to each of the constant buffer resource heaps
// for direct access rendering.
UINT8 *cbvGPUAddress[frameBufferCount]; 

// Constant buffers must be 256-byte aligned which has to do with constant reads 
// on the GPU. We are only able to read at 256 byte intervals from the start of
// a resource heap, so we will make sure that we add padding between the two
// constant buffers in the heap.
int ConstantBufferPerObjectAlignedSize 
	= (sizeof(ModelViewProjectionConstantBuffer) + 255) & ~255;


//==============================================================================
// -- Global variables - Resource objects
//==============================================================================
// Main camera (View & projection matrices).
Camera *mainCamera;
// Main utility helper class (Collection of utility helper funcitons).
Util *mainUtil;
// Main model loader to load various files onto corresponding classes.
MyModelLoader *mainModelLoader;

// Main data structure to hold the models to be initialized and kept.
MySpecialModelObjMtl **mainModelsList;
// Number of models initialized in the mainModelsList data structure.
int numModelsInList;

// CBV alignment offset index counter for models' CBV update.
int countCBVAlignment;

// Main timer.
Timer *timer;

//==============================================================================
// Testing classes
//==============================================================================
// Models
MySpecialModelObjMtl *model1;
MySpecialModelObjMtl *model2;
MySpecialModelObjMtl *model3;
MySpecialModelObjMtl *model4;

// Armatures
MyModelArmature *armature1;

// Animations
MyModelAnimation *testAnim;

// Fonts
MyFont *arialFont;

bool animStart = false;
					   
//##############################################################################
// -- Function prototypes
//##############################################################################
// Create a window.
bool InitializeWindow(HINSTANCE hInstance, int ShowWnd, bool fullscreen);

// Main application loop.
void mainloop();

// Callback function for windows messages.
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

bool InitD3D(); // Initializes direct3d 12.
void Update(double delta); // Update the game logic.

// Update the direct3d pipeline, main render function (update command lists).
void UpdatePipeline(); 
void Render(); // Execute the command list.
void Cleanup(); // Release com ojects and clean up memory.
void WaitForPreviousFrame(); // Wait until gpu is finished with command list.

// Main init funciton to init all the resource objects in one place.
void mainInit(); 

//##############################################################################
//##############################################################################
//##############################################################################
// -- Main function
//##############################################################################
//##############################################################################
//##############################################################################
int WINAPI WinMain(
	HINSTANCE hInstance, 
	HINSTANCE hPrevInstance, 
	LPSTR lpCmdLine,
	int nShowCmd) {

	//##########################################################################
	// -- Initialize resources objects (Models, fonts, animations ... )
	//##########################################################################
	mainInit();

	//##########################################################################
	// -- Create the window
	//##########################################################################
	if (!InitializeWindow(hInstance, nShowCmd, FullScreen)) {
		MessageBox(0, L"Window Initialization - Failed", L"Error", MB_OK);
		return 1;
	}
	//##########################################################################
	// -- Initialize direct3d
	//##########################################################################
	if (!InitD3D()) {
		MessageBox(0, L"Failed to initialize direct3d 12", L"Error", MB_OK);
		Cleanup();
		return 1;
	}

	//##########################################################################
	// -- Start the main loop
	//##########################################################################
	mainloop();

	//##########################################################################
	// We want to wait for the gpu to finish executing the command list 
	// before we start releasing everything.
	//##########################################################################
	WaitForPreviousFrame();

	//##########################################################################
	// -- Close the fence event
	//##########################################################################
	CloseHandle(fenceEvent);

	//##########################################################################
	// -- Clean up everything
	//##########################################################################
	Cleanup();

	return 0;
}

//##############################################################################
// Create and show the window. Do not touch this function if you can.
//##############################################################################
bool InitializeWindow(
	HINSTANCE hInstance,
	int ShowWnd,
	bool fullscreen) {
	if (fullscreen) {
		HMONITOR hmon = MonitorFromWindow(hwnd,
			MONITOR_DEFAULTTONEAREST);
		MONITORINFO mi = { sizeof(mi) };
		GetMonitorInfo(hmon, &mi);

		Width = mi.rcMonitor.right - mi.rcMonitor.left;
		Height = mi.rcMonitor.bottom - mi.rcMonitor.top;
	}

	WNDCLASSEX wc;

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = NULL;
	wc.cbWndExtra = NULL;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 2);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = WindowName;
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	if (!RegisterClassEx(&wc)) {
		MessageBox(NULL, L"Error registering class",
			L"Error", MB_OK | MB_ICONERROR);
		return false;
	}

	hwnd = CreateWindowEx(NULL,
		WindowName,
		WindowTitle,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		Width, Height,
		NULL,
		NULL,
		hInstance,
		NULL);

	if (!hwnd) {
		MessageBox(NULL, L"Error creating window",
			L"Error", MB_OK | MB_ICONERROR);
		return false;
	}

	if (fullscreen) {
		SetWindowLong(hwnd, GWL_STYLE, 0);
	}

	ShowWindow(hwnd, ShowWnd);
	UpdateWindow(hwnd);

	return true;
}

//##############################################################################
// Main application loop. Do not touch this function if you can.
//##############################################################################
void mainloop() {
	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));
	while (Running) {
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			if (msg.message == WM_QUIT)
				break;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else {
			// Run game code

			// We can use delta to update our game logic, passing delta value
			// i can rotate the cubes with cosntant speed no matter how the
			// computer system is fast.
			double delta = timer->GetFrameDelta();
			Update(delta); // Update the game logic

			// Execute the command queue 
			// (Rendering the scene is the result of the 
			// gpu executing the command lists)
			Render(); 
		}
	}
}

//##############################################################################
// Callback function for windows messages.
//##############################################################################
LRESULT CALLBACK WndProc(
	HWND hwnd,
	UINT msg,
	WPARAM wParam,
	LPARAM lParam) {

	// Reference: VK keycode lists: 
	//	https://msdn.microsoft.com/en-us/library/windows/desktop/dd375731(v=vs.85).aspx
	//	http://www.kbdedit.com/manual/low_level_vk_list.html
	// Commonly used keys:
	//		0x51  - Q key
	//		0x42  - E key
	//		0x52  - R key
	//		0x57  - W key
	//		0x41  - A key
	//		0x53  - S key
	//		0x44  - D key

	switch (msg) {
	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE) {
			if (MessageBox(0, L"Are you sure you want to exit?",
				L"Really?", 
				MB_YESNO | MB_ICONQUESTION) == IDYES) {
				Running = false;
				DestroyWindow(hwnd);
			}
		}
		else if (wParam == 0x51) { // Q - Move armature1 armature bones to the left
			//model3->moveModelXYZ(-0.1f, 0, 0);
			for (int i = 0; i < armature1->getNumArmatureBones(); i++) {
				armature1->getArmatureBoneAtIndex(i)->getBoneLine()->moveModelXYZ(-0.1f, 0, 0);
			}
		}
		else if (wParam == 0x45) { // E - Move armature1 armature bones to the right
			for (int i = 0; i < armature1->getNumArmatureBones(); i++) {
				armature1->getArmatureBoneAtIndex(i)->getBoneLine()->moveModelXYZ(0.1f, 0, 0);
			}
		}
		else if (wParam == 0x57) { // W - Rotate armature1 armature bones positive along X axis to font.
			for (int i = 0; i < armature1->getNumArmatureBones(); i++) {
				armature1->getArmatureBoneAtIndex(i)->getBoneLine()->rotateModelXYZ(0.1f, 0, 0);
			}
		}
		else if (wParam == 0x41) { // A - Rotate armature1 armature bones positive along Y axis to the right.
			for (int i = 0; i < armature1->getNumArmatureBones(); i++) {
				armature1->getArmatureBoneAtIndex(i)->getBoneLine()->rotateModelXYZ(0, 0.1f, 0);
			}
		}
		else if (wParam == 0x53) { // S - Rotate armature1 armature bones negative along X axis to back.
			for (int i = 0; i < armature1->getNumArmatureBones(); i++) {
				armature1->getArmatureBoneAtIndex(i)->getBoneLine()->rotateModelXYZ(-0.1f, 0, 0);
			}
		}
		else if (wParam == 0x44) { // D - Rotate armature1 armature bones negative along Y axis to the left.
			for (int i = 0; i < armature1->getNumArmatureBones(); i++) {
				armature1->getArmatureBoneAtIndex(i)->getBoneLine()->rotateModelXYZ(0, -0.1f, 0);
			}
		}

		else if (wParam == 0x5A) { // Z - Rotate armature1 armature bones positive along z axis to right.
			for (int i = 0; i < armature1->getNumArmatureBones(); i++) {
				armature1->getArmatureBoneAtIndex(i)->getBoneLine()->rotateModelXYZ(0, 0, 0.1f);
			}
		}
		else if (wParam == 0x43) { // C - Rotate armature1 armature bones negative along z axis to the left.
			for (int i = 0; i < armature1->getNumArmatureBones(); i++) {
				armature1->getArmatureBoneAtIndex(i)->getBoneLine()->rotateModelXYZ(0, 0, -0.1f);
			}
		}
		else if (wParam == 0x52) { // R- Rotate armature1 armature bones along x axis
			for (int i = 0; i < armature1->getNumArmatureBones(); i++) {
				armature1->getArmatureBoneAtIndex(i)->getBoneLine()->rotateModelXYZ(0.1f, 0, 0);
			}
			//model1->resetModelPositionXYZ();
		}
		else if (wParam == 0x20) { // Space bar - Start current testing animation.
			if (animStart) {
				_RPT1(0, "Animation START\n\n", 0);
			}
			else {
				_RPT1(0, "Animation PAUSE\n\n", 0);
			}
			animStart = !animStart;
		}
		return 0;

	case WM_DESTROY: // x button on top right corner of window was pressed
		Running = false;
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd,
		msg,
		wParam,
		lParam);
}

//##############################################################################
//##############################################################################
//##############################################################################
// Initialize DirectX 12
//##############################################################################
//##############################################################################
//##############################################################################
bool InitD3D() {
	HRESULT hr;
	//##########################################################################
	// -- Create the device
	//##########################################################################
	IDXGIFactory4* dxgiFactory;
	hr = CreateDXGIFactory1(IID_PPV_ARGS(&dxgiFactory));
	if (FAILED(hr)) {
		return false;
	}

	// Adapters are the graphics card 
	// (this includes the embedded graphics on the motherboard).
	IDXGIAdapter1* adapter; 

	// We'll start looking for directx 12  compatible graphics .
	// devices starting at index 0
	int adapterIndex = 0; 

	// Set this to true when a good one was found.
	bool adapterFound = false; 

	// Find first hardware gpu that supports d3d 12.
	while (dxgiFactory->EnumAdapters1(adapterIndex, &adapter) 
		!= DXGI_ERROR_NOT_FOUND) {
		DXGI_ADAPTER_DESC1 desc;
		adapter->GetDesc1(&desc);

		if (desc.Flags & DXGI_ADAPTER_FLAG_SOFTWARE) {
			// We dont want a software device
			continue;
		}

		// We want a device that is compatible with 
		// direct3d 12 (feature level 11 or higher).
		hr = D3D12CreateDevice(
			adapter, 
			D3D_FEATURE_LEVEL_11_0, 
			_uuidof(ID3D12Device),
			nullptr);
		if (SUCCEEDED(hr)) {
			adapterFound = true;
			break;
		}

		adapterIndex++;
	}

	if (!adapterFound) {
		return false;
	}

	// Create the device
	hr = D3D12CreateDevice(
		adapter,
		D3D_FEATURE_LEVEL_11_0,
		IID_PPV_ARGS(&device)
	);

	if (FAILED(hr)) {
		return false;
	}

	//##########################################################################
	// -- Create a direct command queue
	//##########################################################################
	D3D12_COMMAND_QUEUE_DESC cqDesc = {};
	cqDesc.Flags = D3D12_COMMAND_QUEUE_FLAG_NONE;
	// Direct means the gpu can directly execute this command queue.
	cqDesc.Type = D3D12_COMMAND_LIST_TYPE_DIRECT; 

	// Create the command queue.
	hr = device->CreateCommandQueue(&cqDesc, IID_PPV_ARGS(&commandQueue)); 
	if (FAILED(hr)) {
		return false;
	}

	//##########################################################################
	// -- Create the wap Chain (double/tripple buffering)
	//##########################################################################
	DXGI_MODE_DESC backBufferDesc = {}; // this is to describe our display mode
	backBufferDesc.Width = Width; // buffer width
	backBufferDesc.Height = Height; // buffer height
	// format of the buffer (rgba 32 bits, 8 bits for each chanel)
	backBufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM; 

	// describe our multi-sampling. We are not multi-sampling, 
	// so we set the count to 1 (we need at least one sample of course)
	DXGI_SAMPLE_DESC sampleDesc = {};
	// multisample count 
	// (no multisampling, so we just put 1, since we still need 1 sample)
	sampleDesc.Count = 1; 

	// Describe and create the swap chain.
	DXGI_SWAP_CHAIN_DESC swapChainDesc = {};
	swapChainDesc.BufferCount = frameBufferCount; // number of buffers we have
	swapChainDesc.BufferDesc = backBufferDesc; // our back buffer description
	// this says the pipeline will render to this swap chain
	swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT; 
	// dxgi will discard the buffer (data) after we call present
	swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
	swapChainDesc.OutputWindow = hwnd; // handle to our window
	swapChainDesc.SampleDesc = sampleDesc; // our multi-sampling description
	// set to true, then if in fullscreen must call SetFullScreenState with
	// true for full screen to get uncapped fps
	swapChainDesc.Windowed = !FullScreen;

	IDXGISwapChain* tempSwapChain;

	dxgiFactory->CreateSwapChain(
		// the queue will be flushed once the swap chain is created
		commandQueue, 
		&swapChainDesc, // give it the swap chain description we created above
		// store the created swap chain in a temp IDXGISwapChain interface
		&tempSwapChain
	);

	swapChain = static_cast<IDXGISwapChain3*>(tempSwapChain);

	//##########################################################################
	// Back buffer frame index
	//##########################################################################
	frameIndex = swapChain->GetCurrentBackBufferIndex();

	//##########################################################################
	// -- Create the back Buffers (render target views RTV) Descriptor Heap
	//##########################################################################
	// describe an rtv descriptor heap and create
	D3D12_DESCRIPTOR_HEAP_DESC rtvHeapDesc = {};
	// number of descriptors for this heap.
	rtvHeapDesc.NumDescriptors = frameBufferCount; 
	// this heap is a render target view heap
	rtvHeapDesc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_RTV; 

	// This heap will not be directly referenced by the shaders 
	// (not shader visible), as this will store the output from the pipeline
	// otherwise we would set the heap's flag to 
	// D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE
	rtvHeapDesc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;
	hr = device->CreateDescriptorHeap(
		&rtvHeapDesc, 
		IID_PPV_ARGS(&rtvDescriptorHeap));
	if (FAILED(hr)) {
		return false;
	}

	// get the size of a descriptor in this heap 
	// (this is a rtv heap, so only rtv descriptors should be stored in it.
	// descriptor sizes may vary from device to device, 
	// which is why there is no set size and we must ask the 
	// device to give us the size. 
	// we will use this size to increment a descriptor handle offset
	rtvDescriptorSize = device->GetDescriptorHandleIncrementSize(
		D3D12_DESCRIPTOR_HEAP_TYPE_RTV);

	// get a handle to the first descriptor in the descriptor heap. 
	// a handle is basically a pointer,
	// but we cannot literally use it like a c++ pointer.
	CD3DX12_CPU_DESCRIPTOR_HANDLE rtvHandle(
		rtvDescriptorHeap->GetCPUDescriptorHandleForHeapStart());
	 
	// Create a RTV for each buffer 
	// (double buffering is two buffers, tripple buffering is 3).
	for (int i = 0; i < frameBufferCount; i++) {
		// first we get the n'th buffer in the swap chain and store it in the n'th
		// position of our ID3D12Resource array
		hr = swapChain->GetBuffer(i, IID_PPV_ARGS(&renderTargets[i]));
		if (FAILED(hr)) {
			return false;
		}

		// the we "create" a render target view which binds the swap chain
		// buffer (ID3D12Resource[n]) to the rtv handle
		device->CreateRenderTargetView(renderTargets[i], nullptr, rtvHandle);

		// we increment the rtv handle by the rtv descriptor size we got above
		rtvHandle.Offset(1, rtvDescriptorSize);
	}

	//##########################################################################
	// -- Create the command Allocators
	//##########################################################################
	for (int i = 0; i < frameBufferCount; i++) {
		hr = device->CreateCommandAllocator(
			D3D12_COMMAND_LIST_TYPE_DIRECT, 
			IID_PPV_ARGS(&commandAllocator[i]));
		if (FAILED(hr)) {
			return false;
		}
	}

	//##########################################################################
	// -- Create a command List
	//##########################################################################
	// Create the command list with the first allocator.
	hr = device->CreateCommandList(
		0,
		D3D12_COMMAND_LIST_TYPE_DIRECT, 
		commandAllocator[frameIndex],
		NULL,
		IID_PPV_ARGS(&commandList));
	if (FAILED(hr)) {
		return false;
	}

	//##########################################################################
	//-- Create a Fence & Fence Event --//
	//##########################################################################
	// Create the fences.
	for (int i = 0; i < frameBufferCount; i++) {
		hr = device->CreateFence(
			0, 
			D3D12_FENCE_FLAG_NONE, 
			IID_PPV_ARGS(&fence[i]));
		if (FAILED(hr)) {
			return false;
		}
		fenceValue[i] = 0; // Set the initial fence value to 0
	}

	// Create a handle to a fence event.
	fenceEvent = CreateEvent(nullptr, FALSE, FALSE, nullptr);
	if (fenceEvent == nullptr) {
		return false;
	}


	//##########################################################################
	// -- Create root signature
	//##########################################################################
	//		Root parameter
	//			Index 0 - CBV 
	//			Index 1 - SRV
	//##########################################################################
	// Create a root descriptor, which explains where to find the data 
	// for this root parameter.
	D3D12_ROOT_DESCRIPTOR rootCBVDescriptor;
	rootCBVDescriptor.RegisterSpace = 0;
	rootCBVDescriptor.ShaderRegister = 0;

	// Create a descriptor range (descriptor table) and fill it out.
	// this is a range of descriptors inside a descriptor heap.
	D3D12_DESCRIPTOR_RANGE descriptorTableRanges[1]; // only one range now.
	// This is a range of shader resource views (descriptors).
	descriptorTableRanges[0].RangeType = D3D12_DESCRIPTOR_RANGE_TYPE_SRV; 
	// We only have one texture right now, so the range is only 1.
	descriptorTableRanges[0].NumDescriptors = 1; 
	// Start index of the shader registers in the range.
	descriptorTableRanges[0].BaseShaderRegister = 0;
	// Space 0. can usually be zero.
	descriptorTableRanges[0].RegisterSpace = 0; 
	// Appends the range to the end of the root signature descriptor tables.
	descriptorTableRanges[0].OffsetInDescriptorsFromTableStart 
		= D3D12_DESCRIPTOR_RANGE_OFFSET_APPEND; 

	// Create a descriptor table.
	D3D12_ROOT_DESCRIPTOR_TABLE descriptorTable;
	// We only have one range.
	descriptorTable.NumDescriptorRanges = _countof(descriptorTableRanges); 
	// The pointer to the beginning of our ranges array.
	descriptorTable.pDescriptorRanges = &descriptorTableRanges[0]; 

	// Create a root parameter for the root descriptor and fill it out.
	D3D12_ROOT_PARAMETER  rootParameters[2]; // only one parameter right now.
	// This is a constant buffer view root descriptor.
	rootParameters[0].ParameterType = D3D12_ROOT_PARAMETER_TYPE_CBV; 
	// This is the root descriptor for this root parameter.
	rootParameters[0].Descriptor = rootCBVDescriptor; 
	// Pixel shader will be the only shader accessing this parameter for now.
	rootParameters[0].ShaderVisibility = D3D12_SHADER_VISIBILITY_VERTEX; 
	// Fill out the parameter for our descriptor table. 
	// Remember it's a good idea to sort parameters by frequency of change. 
	// Our constant buffer will be changed multiple times per frame, 
	// while our descriptor table will not be changed at all (in this tutorial)
	// this is a descriptor table.
	rootParameters[1].ParameterType 
		= D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE; 
	// This is our descriptor table for this root parameter.
	rootParameters[1].DescriptorTable = descriptorTable; 
	// Pixel shader will be the only shader accessing this parameter for now.
	rootParameters[1].ShaderVisibility = D3D12_SHADER_VISIBILITY_PIXEL; 

	// Create a static sampler for texture rendering.
	D3D12_STATIC_SAMPLER_DESC sampler = {};
	sampler.Filter = D3D12_FILTER_MIN_MAG_MIP_POINT;
	sampler.AddressU = D3D12_TEXTURE_ADDRESS_MODE_BORDER;
	sampler.AddressV = D3D12_TEXTURE_ADDRESS_MODE_BORDER;
	sampler.AddressW = D3D12_TEXTURE_ADDRESS_MODE_BORDER;
	sampler.MipLODBias = 0;
	sampler.MaxAnisotropy = 0;
	sampler.ComparisonFunc = D3D12_COMPARISON_FUNC_NEVER;
	sampler.BorderColor = D3D12_STATIC_BORDER_COLOR_TRANSPARENT_BLACK;
	sampler.MinLOD = 0.0f;
	sampler.MaxLOD = D3D12_FLOAT32_MAX;
	sampler.ShaderRegister = 0;
	sampler.RegisterSpace = 0;
	sampler.ShaderVisibility = D3D12_SHADER_VISIBILITY_PIXEL;

	// Root signature description for init.
	CD3DX12_ROOT_SIGNATURE_DESC rootSignatureDesc;
	// we have 2 root parameters.
	rootSignatureDesc.Init(_countof(rootParameters), 
		// a pointer to the beginning of our root parameters array.
		rootParameters, 
		1, // we have one static sampler.
		&sampler, // a pointer to our static sampler (array).
		// we can deny shader stages here for better performance.
		D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT | 
		D3D12_ROOT_SIGNATURE_FLAG_DENY_HULL_SHADER_ROOT_ACCESS |
		D3D12_ROOT_SIGNATURE_FLAG_DENY_DOMAIN_SHADER_ROOT_ACCESS |
		D3D12_ROOT_SIGNATURE_FLAG_DENY_GEOMETRY_SHADER_ROOT_ACCESS);

	ID3DBlob* errorBuff; // a buffer holding the error data if any.
	ID3DBlob* signature;
	hr = D3D12SerializeRootSignature(
		&rootSignatureDesc, 
		D3D_ROOT_SIGNATURE_VERSION_1, 
		&signature, 
		&errorBuff);
	if (FAILED(hr)) {
		OutputDebugStringA((char*)errorBuff->GetBufferPointer());
		return false;
	}

	// Create root siganture.
	hr = device->CreateRootSignature(
		0, 
		signature->GetBufferPointer(), 
		signature->GetBufferSize(), 
		IID_PPV_ARGS(&rootSignature));
	if (FAILED(hr)) {
		return false;
	}

	//##########################################################################
	// -- Create vertex and pixel shaders for main PSO
	//##########################################################################
	// when debugging, we can compile the shader files at runtime.
	// but for release versions, we can compile the hlsl shaders
	// with fxc.exe to create .cso files, which contain the shader
	// bytecode. We can load the .cso files at runtime to get the
	// shader bytecode, which of course is faster than compiling
	// them at runtime.

	// Compile vertex shader.
	ID3DBlob* vertexShader; // d3d blob for holding vertex shader bytecode.
	hr = D3DCompileFromFile(L"VertexShader.hlsl",
		nullptr,
		nullptr,
		"main",
		// Need to match the version of the Shader Model 
		// in project properties HLSL compiler.
		"vs_5_0", 
		D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION,
		0,
		&vertexShader,
		&errorBuff);
	if (FAILED(hr)) {
		OutputDebugStringA((char*)errorBuff->GetBufferPointer());
		return false;
	}

	// Fill out a shader bytecode structure, which is basically just a pointer
	// to the shader bytecode and the size of the shader bytecode.
	D3D12_SHADER_BYTECODE vertexShaderBytecode = {};
	vertexShaderBytecode.BytecodeLength = vertexShader->GetBufferSize();
	vertexShaderBytecode.pShaderBytecode = vertexShader->GetBufferPointer();

	// Compile pixel shader.
	ID3DBlob* pixelShader;
	hr = D3DCompileFromFile(L"PixelShader.hlsl",
		nullptr,
		nullptr,
		"main",
		// Need to match the version of the Shader Model 
		// in project properties HLSL compiler.
		"ps_5_0",
		D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION,
		0,
		&pixelShader,
		&errorBuff);
	if (FAILED(hr)) {
		OutputDebugStringA((char*)errorBuff->GetBufferPointer());
		return false;
	}

	// Fill out the shader bytecode structure for pixel shader.
	D3D12_SHADER_BYTECODE pixelShaderBytecode = {};
	pixelShaderBytecode.BytecodeLength = pixelShader->GetBufferSize();
	pixelShaderBytecode.pShaderBytecode = pixelShader->GetBufferPointer();

	//##########################################################################
	// -- Create input layout for main PSO
	//##########################################################################
	// The input layout is used by the Input Assembler so that it knows
	// how to read the vertex data bound to it.
	D3D12_INPUT_ELEMENT_DESC inputLayout[] =
	{
		{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT,
			0, 0,
			D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 },
		{ "COLOR", 0, DXGI_FORMAT_R32G32B32_FLOAT,
			0, 12,
			D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 },
		{ "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 
			0, 12, // MUST be 12 or else texture will act weirdly
			D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 },
		{ "NORMAL", 0, DXGI_FORMAT_R32G32_FLOAT,
			0, 24,
			D3D12_INPUT_CLASSIFICATION_PER_VERTEX_DATA, 0 }
	};

	// Fill out an input layout description structure.
	D3D12_INPUT_LAYOUT_DESC inputLayoutDesc = {};

	// We can get the number of elements in an array by 
	// "sizeof(array) / sizeof(arrayElementType)"
	inputLayoutDesc.NumElements 
		= sizeof(inputLayout) / sizeof(D3D12_INPUT_ELEMENT_DESC);
	inputLayoutDesc.pInputElementDescs = inputLayout;

	//##########################################################################
	// -- Create main pipeline state object (PSO)
	//##########################################################################
	// In a real application, you will have many pso's. 
	// for each different shader or different combinations of shaders, 
	// different blend states or different rasterizer states,
	// different topology types (point, line, triangle, patch), 
	// or a different number of render targets you will need a pso

	// VS is the only required shader for a pso. 
	// You might be wondering when a case would be where
	// you only set the VS. It's possible that you have a pso that 
	// only outputs data with the stream
	// output, and not on a render target, which means you would not need 
	// anything after the stream output.

	// A structure to define a pso
	D3D12_GRAPHICS_PIPELINE_STATE_DESC psoDesc = {}; 
	// The structure describing our input layout.
	psoDesc.InputLayout = inputLayoutDesc; 
	// the root signature that describes the input data this pso needs.
	psoDesc.pRootSignature = rootSignature; 
	// Structure describing where to find the vertex shader bytecode
	// and how large it is.
	psoDesc.VS = vertexShaderBytecode; 
	psoDesc.PS = pixelShaderBytecode; // same as VS but for pixel shader.
	// Type of topology we are drawing.
	psoDesc.PrimitiveTopologyType = D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE;
	// Format of the render target.
	psoDesc.RTVFormats[0] = DXGI_FORMAT_R8G8B8A8_UNORM;
	// Must be the same sample description as the swapchain and 
	// depth/stencil buffer.
	psoDesc.SampleDesc = sampleDesc; 
	// Sample mask has to do with multi-sampling. 0xffffffff means 
	// point sampling is done.
	psoDesc.SampleMask = 0xffffffff; 
	// A default rasterizer state.
	psoDesc.RasterizerState = CD3DX12_RASTERIZER_DESC(D3D12_DEFAULT); 
	// A default blent state.
	psoDesc.BlendState = CD3DX12_BLEND_DESC(D3D12_DEFAULT); 
	psoDesc.NumRenderTargets = 1; // We are only binding one render target.
	// A default depth stencil state.
	psoDesc.DepthStencilState = CD3DX12_DEPTH_STENCIL_DESC(D3D12_DEFAULT); 

	// To improve rendering performance, you can cull out(or remove) a primitive 
	// that faces away from the camera.For single - sided primitives, this saves 
	// rendering time because a back - face is not visible.
	// To enable culling, you need to know the winding order 
	// of the vertices(typically counter - clockwise).
	psoDesc.RasterizerState.CullMode = D3D12_CULL_MODE_NONE;

	// Create the pso.
	hr = device->CreateGraphicsPipelineState(
		&psoDesc, 
		IID_PPV_ARGS(&pipelineStateObject));
	if (FAILED(hr)) {
		return false;
	}

	//##########################################################################
	// -- Create vertex and pixel shaders for text PSO
	//##########################################################################
	// Compile vertex shader
	ID3DBlob* textVertexShader; // d3d blob for holding vertex shader bytecode.
	hr = D3DCompileFromFile(L"TextVertexShader.hlsl",
		nullptr,
		nullptr,
		"main",
		// Need to match the version of the Shader Model 
		// in project properties HLSL compiler.
		"vs_5_0",
		D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION,
		0,
		&textVertexShader,
		&errorBuff);
	if (FAILED(hr)) {
		OutputDebugStringA((char*)errorBuff->GetBufferPointer());
		Running = false;
		return false;
	}

	// Fill out a shader bytecode structure, which is basically just a pointer
	// to the shader bytecode and the size of the shader bytecode.
	D3D12_SHADER_BYTECODE textVertexShaderBytecode = {};
	textVertexShaderBytecode.BytecodeLength 
		= textVertexShader->GetBufferSize();
	textVertexShaderBytecode.pShaderBytecode 
		= textVertexShader->GetBufferPointer();

	// Compile pixel shader
	ID3DBlob* textPixelShader;
	hr = D3DCompileFromFile(L"TextPixelShader.hlsl",
		nullptr,
		nullptr,
		"main",
		// Need to match the version of the Shader Model 
		// in project properties HLSL compiler.
		"ps_5_0",
		D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION,
		0,
		&textPixelShader,
		&errorBuff);
	if (FAILED(hr)) {
		OutputDebugStringA((char*)errorBuff->GetBufferPointer());
		Running = false;
		return false;
	}

	// Fill out the shader bytecode structure for pixel shader
	D3D12_SHADER_BYTECODE textPixelShaderBytecode = {};
	textPixelShaderBytecode.BytecodeLength 
		= textPixelShader->GetBufferSize();
	textPixelShaderBytecode.pShaderBytecode 
		= textPixelShader->GetBufferPointer();

	//##########################################################################
	// -- Create input layout for text PSO
	//##########################################################################
	// The input layout is used by the Input Assembler so that it knows.
	// how to read the vertex data bound to it.
	D3D12_INPUT_ELEMENT_DESC textInputLayout[] =
	{
		{ "POSITION", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 
			0, 0, D3D12_INPUT_CLASSIFICATION_PER_INSTANCE_DATA, 1 },
		{ "TEXCOORD", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 
			0, 16, D3D12_INPUT_CLASSIFICATION_PER_INSTANCE_DATA, 1 },
		{ "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 
			0, 32, D3D12_INPUT_CLASSIFICATION_PER_INSTANCE_DATA, 1 }
	};

	// Fill out an input layout description structure.
	D3D12_INPUT_LAYOUT_DESC textInputLayoutDesc = {};

	// we can get the number of elements in an array by 
	// "sizeof(array) / sizeof(arrayElementType)"
	textInputLayoutDesc.NumElements 
		= sizeof(textInputLayout) / sizeof(D3D12_INPUT_ELEMENT_DESC);
	textInputLayoutDesc.pInputElementDescs = textInputLayout;

	//##########################################################################
	// Create the text pipeline state object (PSO) 
	//##########################################################################
	D3D12_GRAPHICS_PIPELINE_STATE_DESC textpsoDesc = {};
	textpsoDesc.InputLayout = textInputLayoutDesc;
	textpsoDesc.pRootSignature = rootSignature;
	textpsoDesc.VS = textVertexShaderBytecode;
	textpsoDesc.PS = textPixelShaderBytecode;
	textpsoDesc.PrimitiveTopologyType = D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE;
	textpsoDesc.RTVFormats[0] = DXGI_FORMAT_R8G8B8A8_UNORM;
	textpsoDesc.SampleDesc = sampleDesc;
	textpsoDesc.SampleMask = 0xffffffff;
	textpsoDesc.RasterizerState = CD3DX12_RASTERIZER_DESC(D3D12_DEFAULT);

	D3D12_BLEND_DESC textBlendStateDesc = {};
	textBlendStateDesc.AlphaToCoverageEnable = FALSE;
	textBlendStateDesc.IndependentBlendEnable = FALSE;
	textBlendStateDesc.RenderTarget[0].BlendEnable = TRUE;
	textBlendStateDesc.RenderTarget[0].SrcBlend = D3D12_BLEND_SRC_ALPHA;
	textBlendStateDesc.RenderTarget[0].DestBlend = D3D12_BLEND_ONE;
	textBlendStateDesc.RenderTarget[0].BlendOp = D3D12_BLEND_OP_ADD;
	textBlendStateDesc.RenderTarget[0].SrcBlendAlpha = D3D12_BLEND_SRC_ALPHA;
	textBlendStateDesc.RenderTarget[0].DestBlendAlpha = D3D12_BLEND_ONE;
	textBlendStateDesc.RenderTarget[0].BlendOpAlpha = D3D12_BLEND_OP_ADD;
	textBlendStateDesc.RenderTarget[0].RenderTargetWriteMask 
		= D3D12_COLOR_WRITE_ENABLE_ALL;
	textpsoDesc.BlendState = textBlendStateDesc;
	textpsoDesc.NumRenderTargets = 1;

	D3D12_DEPTH_STENCIL_DESC textDepthStencilDesc 
		= CD3DX12_DEPTH_STENCIL_DESC(D3D12_DEFAULT);
	textDepthStencilDesc.DepthEnable = false;
	textpsoDesc.DepthStencilState = textDepthStencilDesc;

	// Create the text pso
	hr = device->CreateGraphicsPipelineState(
		&textpsoDesc, 
		IID_PPV_ARGS(&textPSO));
	if (FAILED(hr)) {
		Running = false;
		return false;
	}

	//##########################################################################
	// -- Create the depth/stencil buffer
	//##########################################################################
	// Create a depth stencil descriptor heap so we can get a pointer 
	// to the depth stencil buffer.
	D3D12_DESCRIPTOR_HEAP_DESC dsvHeapDesc = {};
	dsvHeapDesc.NumDescriptors = 1;
	dsvHeapDesc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_DSV;
	dsvHeapDesc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;
	hr = device->CreateDescriptorHeap(
		&dsvHeapDesc,
		IID_PPV_ARGS(&dsDescriptorHeap));
	if (FAILED(hr)) {
		Running = false;
	}

	D3D12_DEPTH_STENCIL_VIEW_DESC depthStencilDesc = {};
	depthStencilDesc.Format = DXGI_FORMAT_D32_FLOAT;
	depthStencilDesc.ViewDimension = D3D12_DSV_DIMENSION_TEXTURE2D;
	depthStencilDesc.Flags = D3D12_DSV_FLAG_NONE;

	D3D12_CLEAR_VALUE depthOptimizedClearValue = {};
	depthOptimizedClearValue.Format = DXGI_FORMAT_D32_FLOAT;
	depthOptimizedClearValue.DepthStencil.Depth = 1.0f;
	depthOptimizedClearValue.DepthStencil.Stencil = 0;

	device->CreateCommittedResource(
		&CD3DX12_HEAP_PROPERTIES(D3D12_HEAP_TYPE_DEFAULT),
		D3D12_HEAP_FLAG_NONE,
		&CD3DX12_RESOURCE_DESC::Tex2D(
			DXGI_FORMAT_D32_FLOAT,
			Width, Height,
			1, 0, 1, 0,
			D3D12_RESOURCE_FLAG_ALLOW_DEPTH_STENCIL),
		D3D12_RESOURCE_STATE_DEPTH_WRITE,
		&depthOptimizedClearValue,
		IID_PPV_ARGS(&depthStencilBuffer)
	);
	dsDescriptorHeap->SetName(L"Depth/Stencil Resource Heap");

	device->CreateDepthStencilView(
		depthStencilBuffer, 
		&depthStencilDesc, 
		dsDescriptorHeap->GetCPUDescriptorHandleForHeapStart());

	//##########################################################################
	// -- Create the descriptor heap that will store our SRV
	//##########################################################################
	D3D12_DESCRIPTOR_HEAP_DESC heapDesc = {};
	heapDesc.NumDescriptors = 2;
	heapDesc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;
	heapDesc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;
	hr = device->CreateDescriptorHeap(
		&heapDesc, 
		IID_PPV_ARGS(&srvDescriptorHeap));
	if (FAILED(hr)) {
		Running = false;
	}

	//##########################################################################
	// -- Fill out the viewport
	//##########################################################################
	viewport.TopLeftX = 0;
	viewport.TopLeftY = 0;
	viewport.Width = (float)Width;
	viewport.Height = (float)Height;
	viewport.MinDepth = 0.0f;
	viewport.MaxDepth = 1.0f;

	//##########################################################################
	// -- Fill out a scissor rect
	//##########################################################################
	scissorRect.left = 0;
	scissorRect.top = 0;
	scissorRect.right = Width;
	scissorRect.bottom = Height;
	//##########################################################################

	//##########################################################################
	// -- Init SRV handles
	//##########################################################################
	// SRV handle on CPU for SRV creation.
	CD3DX12_CPU_DESCRIPTOR_HANDLE *srvCpuHandle 
		= new CD3DX12_CPU_DESCRIPTOR_HANDLE(
			srvDescriptorHeap->GetCPUDescriptorHandleForHeapStart());
	// SRV handle on GPU to be set to each model objects for rendering.
	CD3DX12_GPU_DESCRIPTOR_HANDLE *srvGpuHandle
		= new CD3DX12_GPU_DESCRIPTOR_HANDLE(
			srvDescriptorHeap->GetGPUDescriptorHandleForHeapStart());
	// SRV handle size for handle offset incrementing.
	UINT srvHandleSize 
		= device->GetDescriptorHandleIncrementSize(
			D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV);

	//##########################################################################
	// -- Init fonts
	//##########################################################################
	arialFont->initMyFont(
		device, commandList, mainUtil, 
		srvDescriptorHeap, srvCpuHandle, srvGpuHandle, srvHandleSize, 
		L"\\Arial.fnt", Width, Height);

	//##########################################################################
	// -- Init models
	//##########################################################################
	// Rectangular OBJ 
	model1->initMySpecialModelObjMtl(
		device, commandList, mainUtil, 
		srvDescriptorHeap, srvCpuHandle, srvGpuHandle, srvHandleSize);
	model1->setModelPositionXYZ(1.0f, 0, 0);
	
	//==========================================================================
	// Coordinate axis
	//==========================================================================
	model2->initMySpecialModelObjMtl(
		device, commandList, mainUtil, 
		srvDescriptorHeap, srvCpuHandle, srvGpuHandle, srvHandleSize);
	//model2->setModelPositionXYZ(-3.0f, -3.0f, 0);
	
	XMVECTOR *coordinateAxisScreenCoord = new XMVECTOR();
	*coordinateAxisScreenCoord = XMVectorSet(120.0f, 500.0f, 0.99f, 1.0f);
	mainUtil->printXMVECTOR3(
		"coordinateAxisScreenCoord",
		coordinateAxisScreenCoord);
	// Calculate the projected world space to set the coordinate axis model
	XMVECTOR *coordinateAxisLocalCoordUnprojected
		= mainUtil->get3DworldSpaceFrom2DscreenSpace(
			coordinateAxisScreenCoord,
			&XMMatrixIdentity(),
			&XMLoadFloat4x4(mainCamera->getCameraViewMat()),
			&XMLoadFloat4x4(mainCamera->getCameraProjMat()),
			&viewport);
	mainUtil->printXMVECTOR4(
		"coordinateAxisLocalCoordUnprojected",
		coordinateAxisLocalCoordUnprojected);
	// Set init main coordinate axis position on unprojected world space
	model2->setModelPositionXYZ(
		coordinateAxisLocalCoordUnprojected->m128_f32[0],
		coordinateAxisLocalCoordUnprojected->m128_f32[1],
		coordinateAxisLocalCoordUnprojected->m128_f32[2]);


	//==========================================================================
	// Rectangular WYO
	//==========================================================================
	model3->initMySpecialModelObjMtl(device, commandList, mainUtil, srvDescriptorHeap, srvCpuHandle, srvGpuHandle, srvHandleSize);
	model3->setModelPositionXYZ(-4.0f, 0, 0);

	// Minions
	//model4->initMySpecialModelObjMtl(device, commandList, mainUtil, srvDescriptorHeap, &srvCpuHandle, srvDescriptorSize, srvDescriptorOffsetIndex);
	//model4->setModelPositionXYZ(0.0f, 0, 0);
	//for (int i = 0; i < model1->getModelObj()->getTextureCount(); i++) {
	//	_RPT1(0, "TEXTURE : %f, %f\n", model1->getModelVertexPositionColorTextureCoordNormalBuffer()[i].tex.x, model1->getModelVertexPositionColorTextureCoordNormalBuffer()[i].tex.y);
	//}
	
	//##########################################################################
	// -- Create the constant buffer resource heap
	//##########################################################################
	// We will update the constant buffer one or more times per frame, so we will use only an upload heap
	// unlike previously we used an upload heap to upload the vertex and index data, and then copied over
	// to a default heap. If you plan to use a resource for more than a couple frames, it is usually more
	// efficient to copy to a default heap where it stays on the gpu. In this case, our constant buffer
	// will be modified and uploaded at least once per frame, so we only use an upload heap

	// first we will create a resource heap (upload heap) for each frame for the cubes constant buffers
	// As you can see, we are allocating 64KB for each resource we create. Buffer resource heaps must be
	// an alignment of 64KB. We are creating 3 resources, one for each frame. Each constant buffer is 
	// only a 4x4 matrix of floats in this tutorial. So with a float being 4 bytes, we have 
	// 16 floats in one constant buffer, and we will store 2 constant buffers in each
	// heap, one for each cube, thats only 64x2 bits, or 128 bits we are using for each
	// resource, and each resource must be at least 64KB (65536 bits)
	for (int i = 0; i < frameBufferCount; ++i) {
		// create resource for cube 1
		hr = device->CreateCommittedResource(
			// this heap will be used to upload the constant buffer data
			&CD3DX12_HEAP_PROPERTIES(D3D12_HEAP_TYPE_UPLOAD), 
			D3D12_HEAP_FLAG_NONE, // no flags
			// size of the resource heap. 
			// Must be a multiple of 64KB for single-textures 
			// and constant buffers
			//&CD3DX12_RESOURCE_DESC::Buffer(1024 * 64),
			&CD3DX12_RESOURCE_DESC::Buffer(
				D3D12_DEFAULT_RESOURCE_PLACEMENT_ALIGNMENT),
			// will be data that is read from so we keep it in the 
			// generic read state
			D3D12_RESOURCE_STATE_GENERIC_READ,
			// we do not have use an optimized clear value for constant buffers
			nullptr, 
			IID_PPV_ARGS(&constantBufferUploadHeaps[i]));
		constantBufferUploadHeaps[i]->SetName(
			L"Constant Buffer Upload Resource Heap");

		ZeroMemory(&cbPerObject, sizeof(cbPerObject));

		// We do not intend to read from this resource on the CPU. 
		// (so end is less than or equal to begin)
		CD3DX12_RANGE readRange(0, 0);	

		// map the resource heap to get a gpu virtual address to the 
		// beginning of the heap
		hr = constantBufferUploadHeaps[i]->Map(
			0, 
			&readRange, 
			reinterpret_cast<void**>(&cbvGPUAddress[i]));

		//######################################################################
		// -- Models constant buffer init
		//######################################################################
		// Because of the constant read alignment requirements, 
		// constant buffer views must be 256 bit aligned. 
		// Our buffers are smaller than 256 bits,
		// so we need to add spacing between the two buffers, 
		// so that the second buffer starts at 256 bits from 
		// the beginning of the resource heap.
		memcpy(cbvGPUAddress[i], &cbPerObject, sizeof(cbPerObject));
		memcpy(cbvGPUAddress[i] + ConstantBufferPerObjectAlignedSize, &cbPerObject, sizeof(cbPerObject));
		memcpy(cbvGPUAddress[i] + ConstantBufferPerObjectAlignedSize * 2, &cbPerObject, sizeof(cbPerObject));
		memcpy(cbvGPUAddress[i] + ConstantBufferPerObjectAlignedSize * 3, &cbPerObject, sizeof(cbPerObject));
	
		model1->setModelCBVAlignmentIndex(0);
		model2->setModelCBVAlignmentIndex(1);
		model3->setModelCBVAlignmentIndex(2);
		//model4->setModelCBVAlignmentIndex(3);

		countCBVAlignment = 3;

		// Temp armature object CBV init
		for (int k = 0; k < armature1->getNumArmatureBones(); k++) {
			// Set each model's CBV alignment index
			armature1->getArmatureBoneAtIndex(k)->getBoneLine()->setLineCBVAlignmentIndex(countCBVAlignment);
			_RPT1(0, "this->armature->getArmatureBoneAtIndex(k)->getBoneLine()->getLineCBVAlignmentIndex() : %d\n", armature1->getArmatureBoneAtIndex(k)->getBoneLine()->getLineCBVAlignmentIndex());
			memcpy(cbvGPUAddress[i] + ConstantBufferPerObjectAlignedSize*(countCBVAlignment), &cbPerObject, sizeof(cbPerObject));
			countCBVAlignment++;
		}
	}

	// Temp armature object line models init - to represent the bones
	for (int i = 0; i < armature1->getNumArmatureBones(); i++) {
		if (armature1->getArmatureBoneAtIndex(i) != NULL) {
			armature1->getArmatureBoneAtIndex(i)->getBoneLine()->createLine(device, commandList);
		}
	}

	//##########################################################################
	// Now we execute the command list to upload the initial assets 
	// (triangle data)
	//##########################################################################
	commandList->Close();
	ID3D12CommandList* ppCommandLists[] = { commandList };
	commandQueue->ExecuteCommandLists(_countof(ppCommandLists), ppCommandLists);

	//##########################################################################
	// Increment the fence value now, 
	// otherwise the buffer might not be uploaded by the time we start drawing
	//##########################################################################
	fenceValue[frameIndex]++;
	hr = commandQueue->Signal(fence[frameIndex], fenceValue[frameIndex]);
	if (FAILED(hr)) {
		Running = false;
	}

	return true;
}

//##############################################################################
//##############################################################################
//##############################################################################
// -- Main update function
//##############################################################################
//##############################################################################
//##############################################################################
// Frame counter
int frameCount = 0;
// Animation frame counter
int animCount = 0;
void Update(double delta) {
	XMMATRIX wvpMat = XMLoadFloat4x4(model1->getModelWorldMat()) *
		XMLoadFloat4x4(mainCamera->getCameraViewMat()) *
		XMLoadFloat4x4(mainCamera->getCameraProjMat());
	XMMATRIX transposed = XMMatrixTranspose(wvpMat); // must transpose wvp matrix for the gpu
	XMStoreFloat4x4(&cbPerObject.wvpMat, transposed); // store transposed wvp matrix in constant buffer
	memcpy(cbvGPUAddress[frameIndex] + ConstantBufferPerObjectAlignedSize*model1->getModelCBVAlignmentIndex(), &cbPerObject, sizeof(cbPerObject));

	wvpMat = XMLoadFloat4x4(model2->getModelWorldMat()) *
		XMLoadFloat4x4(mainCamera->getCameraViewMat()) *
		XMLoadFloat4x4(mainCamera->getCameraProjMat());
	transposed = XMMatrixTranspose(wvpMat); // must transpose wvp matrix for the gpu
	XMStoreFloat4x4(&cbPerObject.wvpMat, transposed); // store transposed wvp matrix in constant buffer
	memcpy(cbvGPUAddress[frameIndex] + ConstantBufferPerObjectAlignedSize*model2->getModelCBVAlignmentIndex(), &cbPerObject, sizeof(cbPerObject));

	wvpMat = XMLoadFloat4x4(model3->getModelWorldMat()) *
		XMLoadFloat4x4(mainCamera->getCameraViewMat()) *
		XMLoadFloat4x4(mainCamera->getCameraProjMat());
	transposed = XMMatrixTranspose(wvpMat); // must transpose wvp matrix for the gpu
	XMStoreFloat4x4(&cbPerObject.wvpMat, transposed); // store transposed wvp matrix in constant buffer
	memcpy(cbvGPUAddress[frameIndex] + ConstantBufferPerObjectAlignedSize*model3->getModelCBVAlignmentIndex(), &cbPerObject, sizeof(cbPerObject));

	//wvpMat = XMLoadFloat4x4(model4->getModelWorldMat()) *
	//	XMLoadFloat4x4(mainCamera->getCameraViewMat()) *
	//	XMLoadFloat4x4(mainCamera->getCameraProjMat());
	//transposed = XMMatrixTranspose(wvpMat); // must transpose wvp matrix for the gpu
	//XMStoreFloat4x4(&cbPerObject.wvpMat, transposed); // store transposed wvp matrix in constant buffer
	//memcpy(cbvGPUAddress[frameIndex] + ConstantBufferPerObjectAlignedSize*model4->getModelCBVAlignmentIndex(), &cbPerObject, sizeof(cbPerObject));

	//##########################################################################
	// Animation test
	//##########################################################################
	if (animStart && frameCount % 2000 == 0) {
		
		/*_RPT1(0, "frameCount : %d\n", frameCount);
		_RPT1(0, "testAnim->getNumAnimationBones() : %d\n", testAnim->getNumAnimationBones());
		_RPT1(0, "armature1->getNumArmatureBones() : %d\n", armature1->getNumArmatureBones());*/

		for (int i = 0; i < testAnim->getNumAnimationBones(); i++) {
			for (int j = 0; j < armature1->getNumArmatureBones(); j++) {
				if (strcmp(testAnim->getAnimationBoneAtIndex(i)->getAnimationBoneName(), armature1->getArmatureBoneAtIndex(j)->getArmatureBoneName()) == 0) {
					// Trial 1 - Set pose bone matrix to line model matrix.
					/*XMFLOAT4X4 *arm1LineWorldMat = armature1->getArmatureBoneAtIndex(j)->getBoneLine()->getLineWorldMat();
					XMFLOAT4X4 *curAnimationFrame = testAnim->getAnimationBoneAtIndex(i)->getAnimationFrameAtIndex(animCount);
					armature1->getArmatureBoneAtIndex(j)->getBoneLine()->setLineWorldMat(curAnimationFrame);*/

					// Trial 2 - Translation, Rotation and Scaling.
					MyModelAnimationBone *curAnimBone = testAnim->getAnimationBoneAtIndex(i);
					MyModelArmatureBone *curArmaBone = armature1->getArmatureBoneAtIndex(j);
					XMFLOAT3 translationVec = curAnimBone->getAnimationFrameAtIndex(animCount)->translationVec;
					XMFLOAT4 rotationQuat = curAnimBone->getAnimationFrameAtIndex(animCount)->rotationQuat;
					XMFLOAT3 scalingVec = curAnimBone->getAnimationFrameAtIndex(animCount)->scalingVec;
					Line *curArmaBoneLine = curArmaBone->getBoneLine();

					curArmaBoneLine->moveModelXYZ(translationVec.x, translationVec.y, translationVec.z);
					curArmaBoneLine->rotateModelXYZ(rotationQuat.x, rotationQuat.y, rotationQuat.z);
					curArmaBoneLine->scaleModelXYZ(scalingVec.x, scalingVec.y, scalingVec.z);

					//// Trial 3 - Set pose bone local matrix.
					////MyModelAnimationBone *curAnimBone = testAnim->getAnimationBoneAtIndex(i);
					////MyModelArmatureBone *curArmaBone = armature1->getArmatureBoneAtIndex(j);
					////Line *curArmaBoneLine = curArmaBone->getBoneLine();
					////XMFLOAT4X4 animPoseBoneMat = curAnimBone->getAnimationFrameAtIndex(i)->worldMatrix;
					//mainUtil->printXMFLOAT4x4("animPoseBoneMat", &curAnimBone->getAnimationFrameAtIndex(animCount)->worldMatrix);
					//curArmaBoneLine->setLineWorldMat(&curAnimBone->getAnimationFrameAtIndex(animCount)->worldMatrix);
				}
			}
		}
		// Increment animation counter to apply animation
		animCount++;

		// Currently testing the animation only with 4 frames exported
		if (animCount >= testAnim->getAnimationBones()->at(0)->getAnimationFrames()->size()) {
			animCount = 0; // Reset
		}
	}

	//##########################################################################
	// Temp armature object CBV update
	//##########################################################################
	for (int k = 0; k < armature1->getNumArmatureBones(); k++) {
		wvpMat = 
			XMMatrixTranspose(XMLoadFloat4x4(armature1->getArmatureBoneAtIndex(k)->getBoneLine()->getLineWorldMat())) * // Need to transposed the animating bone's world matrix to apply animation
			XMLoadFloat4x4(armature1->getArmatureBoneAtIndex(k)->getBoneLine()->getLineTranslationMat()) * // Multiply translation matrix
			XMLoadFloat4x4(armature1->getArmatureBoneAtIndex(k)->getBoneLine()->getLineRotationMat()) * // Multiply rotation matrix
			XMLoadFloat4x4(armature1->getArmatureBoneAtIndex(k)->getBoneLine()->getLineScaleMat()) * // Multiply scaling matrix
			XMLoadFloat4x4(mainCamera->getCameraViewMat()) * // Multiply main camera view matrix
			XMLoadFloat4x4(mainCamera->getCameraProjMat()); // Multiply main camera projection matrix
		transposed = XMMatrixTranspose(wvpMat); // must transpose wvp matrix for the gpu
		XMStoreFloat4x4(&cbPerObject.wvpMat, transposed); // store transposed wvp matrix in constant buffer

		// Update CBV
		memcpy(
			cbvGPUAddress[frameIndex] 
				+ ConstantBufferPerObjectAlignedSize*(armature1->getArmatureBoneAtIndex(k)->getBoneLine()->getLineCBVAlignmentIndex()),
			&cbPerObject,
			sizeof(cbPerObject));
	}

	// Increment frame counter.
	frameCount++;
}

//##############################################################################
//##############################################################################
//##############################################################################
// -- Main update pipeline function
//##############################################################################
//##############################################################################
//##############################################################################
void UpdatePipeline() {
	HRESULT hr;

	// We have to wait for the gpu to finish with 
	// the command allocator before we reset it
	WaitForPreviousFrame();

	// we can only reset an allocator once the gpu is done with it
	// resetting an allocator frees the memory that 
	// the command list was stored in
	hr = commandAllocator[frameIndex]->Reset();
	if (FAILED(hr)) {
		Running = false;
	}

	// Reset the command list. by resetting the command list we are putting it
	// into a recording state so we can start recording commands into the 
	// command allocator. the command allocator that we reference here may have 
	// multiple command lists associated with it, but only one can be 
	// recording at any time. Make sure that any other command lists associated
	// to this command allocator are in the closed state (not recording).
	// Here you will pass an initial pipeline state object as the second 
	// parameter, but in this tutorial we are only clearing the rtv, 
	// and do not actually need anything but an initial default pipeline, 
	// which is what we get by setting the second parameter to NULL
	hr = commandList->Reset(commandAllocator[frameIndex], pipelineStateObject);
	if (FAILED(hr)) {
		Running = false;
	}

	//##########################################################################
	// Resource barrier transition (Present --> Render target)
	//##########################################################################
	// here we start recording commands into the commandList 
	// (which all the commands will be stored in the commandAllocator)

	// transition the "frameIndex" render target from the present state to 
	// the render target state so the command list 
	// draws to it starting from here
	commandList->ResourceBarrier(
		1,
		&CD3DX12_RESOURCE_BARRIER::Transition(
			renderTargets[frameIndex], 
			D3D12_RESOURCE_STATE_PRESENT, 
			D3D12_RESOURCE_STATE_RENDER_TARGET));

	// here we again get the handle to our current render target view 
	// so we can set it as the render target in the output merger stage 
	// of the pipeline
	CD3DX12_CPU_DESCRIPTOR_HANDLE rtvHandle(
		rtvDescriptorHeap->GetCPUDescriptorHandleForHeapStart(),
		frameIndex, 
		rtvDescriptorSize);

	// get a handle to the depth/stencil buffer
	CD3DX12_CPU_DESCRIPTOR_HANDLE dsvHandle(
		dsDescriptorHeap->GetCPUDescriptorHandleForHeapStart());

	// set the render target for the output merger stage 
	// (the output of the pipeline)
	commandList->OMSetRenderTargets(1, &rtvHandle, FALSE, &dsvHandle);

	// Clear the render target by using the ClearRenderTargetView command
	const float clearColor[] = { 0.0f, 0.2f, 0.4f, 1.0f };
	commandList->ClearRenderTargetView(rtvHandle, clearColor, 0, nullptr);

	// clear the depth/stencil buffer
	commandList->ClearDepthStencilView(
		dsDescriptorHeap->GetCPUDescriptorHandleForHeapStart(), 
		D3D12_CLEAR_FLAG_DEPTH, 
		1.0f, 
		0, 
		0, 
		nullptr);

	// set root signature
	commandList->SetGraphicsRootSignature(rootSignature);

	// set the descriptor heap
	ID3D12DescriptorHeap* ppHeaps[] = { srvDescriptorHeap };
	commandList->SetDescriptorHeaps(_countof(ppHeaps), ppHeaps);

	//##########################################################################
	// -- Render models
	//##########################################################################
	UINT srvDescriptorSize
		= device->GetDescriptorHandleIncrementSize(
			D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV);
	CD3DX12_GPU_DESCRIPTOR_HANDLE srvGpuHandle(
		srvDescriptorHeap->GetGPUDescriptorHandleForHeapStart(),
		frameIndex,
		srvDescriptorSize);

	srvGpuHandle.InitOffsetted(
		srvDescriptorHeap->GetGPUDescriptorHandleForHeapStart(),
		0, // Texture SRV of current model
		srvDescriptorSize);

	commandList->SetGraphicsRootDescriptorTable(1, srvGpuHandle);

	// draw triangle
	commandList->RSSetViewports(1, &viewport); // set the viewports
	commandList->RSSetScissorRects(1, &scissorRect); // set the scissor rects
	// set the primitive topology
	commandList->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST); 

	//==========================================================================
	// Model 1
	//==========================================================================
	commandList->SetGraphicsRootDescriptorTable(1, *model1->getModelSRVDescriptorOffsetHandleGPU());

	commandList->SetGraphicsRootConstantBufferView(0, constantBufferUploadHeaps[frameIndex]->GetGPUVirtualAddress() + ConstantBufferPerObjectAlignedSize*model1->getModelCBVAlignmentIndex());
	//commandList->SetGraphicsRootConstantBufferView(0, constantBufferUploadHeaps[frameIndex]->GetGPUVirtualAddress() + ConstantBufferPerObjectAlignedSize*2);
	commandList->RSSetViewports(1, &viewport); // set the viewports
	commandList->RSSetScissorRects(1, &scissorRect); // set the scissor rects
	commandList->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST); // set the primitive topology
	
	commandList->IASetVertexBuffers(0, 1, &model1->getVertexBufferView()); // set the vertex buffer (using the vertex buffer view)
	commandList->IASetIndexBuffer(&model1->getIndexBufferView());
	//commandList->DrawIndexedInstanced(model1->getIndicesCount(), 1, 0, 0, 0);

	//==========================================================================
	// Model 2 - coordinate axis
	//==========================================================================
	commandList->SetGraphicsRootDescriptorTable(1, *model2->getModelSRVDescriptorOffsetHandleGPU());

	commandList->SetGraphicsRootConstantBufferView(0, constantBufferUploadHeaps[frameIndex]->GetGPUVirtualAddress() + ConstantBufferPerObjectAlignedSize*model2->getModelCBVAlignmentIndex());
	commandList->RSSetViewports(1, &viewport); // set the viewports
	commandList->RSSetScissorRects(1, &scissorRect); // set the scissor rects
	commandList->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST); // set the primitive topology

	commandList->IASetVertexBuffers(0, 1, &model2->getVertexBufferView()); // set the vertex buffer (using the vertex buffer view)
	commandList->IASetIndexBuffer(&model2->getIndexBufferView());
	commandList->DrawIndexedInstanced(model2->getIndicesCount(), 1, 0, 0, 0);

	//==========================================================================
	// Model 3 - Rectangular model
	//==========================================================================
	commandList->SetGraphicsRootDescriptorTable(1, *model3->getModelSRVDescriptorOffsetHandleGPU());

	commandList->SetGraphicsRootConstantBufferView(0, constantBufferUploadHeaps[frameIndex]->GetGPUVirtualAddress() + ConstantBufferPerObjectAlignedSize*model3->getModelCBVAlignmentIndex());
	commandList->RSSetViewports(1, &viewport); // set the viewports
	commandList->RSSetScissorRects(1, &scissorRect); // set the scissor rects
	commandList->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST); // set the primitive topology

	commandList->IASetVertexBuffers(0, 1, &model3->getVertexBufferView()); // set the vertex buffer (using the vertex buffer view)
	commandList->IASetIndexBuffer(&model3->getIndexBufferView());
	commandList->DrawIndexedInstanced(model3->getIndicesCount(), 1, 0, 0, 0);


	//srvGpuHandle.InitOffsetted(
	//	srvDescriptorHeap->GetGPUDescriptorHandleForHeapStart(),
	//	model4->getModelSRVDescriptorIndex(),
	//	srvDescriptorSize);
	//commandList->SetGraphicsRootDescriptorTable(1, srvGpuHandle);

	//commandList->SetGraphicsRootConstantBufferView(0, constantBufferUploadHeaps[frameIndex]->GetGPUVirtualAddress() + ConstantBufferPerObjectAlignedSize*model4->getModelCBVAlignmentIndex());
	//commandList->RSSetViewports(1, &viewport); // set the viewports
	//commandList->RSSetScissorRects(1, &scissorRect); // set the scissor rects
	//commandList->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST); // set the primitive topology

	//commandList->IASetVertexBuffers(0, 1, &model4->getVertexBufferView()); // set the vertex buffer (using the vertex buffer view)
	//commandList->IASetIndexBuffer(&model4->getIndexBufferView());
	//commandList->DrawIndexedInstanced(model4->getIndicesCount(), 1, 0, 0, 0);




	//==========================================================================
	// Temp armature, rendering line models inside each armature bones
	//==========================================================================
	for (int i = 0; i < armature1->getNumArmatureBones(); i++) {
		if (armature1->getArmatureBoneAtIndex(i) != NULL) {
			commandList->SetGraphicsRootConstantBufferView(0, constantBufferUploadHeaps[frameIndex]->GetGPUVirtualAddress() + ConstantBufferPerObjectAlignedSize*armature1->getArmatureBoneAtIndex(i)->getBoneLine()->getLineCBVAlignmentIndex());
			commandList->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_LINELIST);
			commandList->IASetVertexBuffers(0, 1, &armature1->getArmatureBoneAtIndex(i)->getBoneLine()->getVertexLineBufferView());
			commandList->IASetIndexBuffer(&armature1->getArmatureBoneAtIndex(i)->getBoneLine()->getIndexLineBufferView());
			commandList->DrawIndexedInstanced(2, 1, 0, 0, 0);
		}
	}

	//==========================================================================
	// -- Render fonts 
	//==========================================================================
	arialFont->RenderText(
		textPSO, 
		commandList, 
		dsDescriptorHeap, 
		frameIndex, 
		std::wstring(L"FPS: ") + std::to_wstring(timer->fps),
		XMFLOAT2(0.02f, 0.01f), // Position on screen
		XMFLOAT2(2.0f, 2.0f));  // Font scale


	//##########################################################################
	// Resource barrier transition back (Render target --> Present)
	//##########################################################################
	// transition the "frameIndex" render target from the render target state to the present state. If the debug layer is enabled, you will receive a
	// warning if present is called on the render target when it's not in the present state
	commandList->ResourceBarrier(
		1, 
		&CD3DX12_RESOURCE_BARRIER::Transition(
			renderTargets[frameIndex], 
			D3D12_RESOURCE_STATE_RENDER_TARGET, 
			D3D12_RESOURCE_STATE_PRESENT));

	hr = commandList->Close();
	if (FAILED(hr)) {
		Running = false;
	}
}

//##############################################################################
//##############################################################################
//##############################################################################
// -- Main render function executes the command list. 
//		Do not touch this functionn if you can.
//##############################################################################
//##############################################################################
//##############################################################################
void Render() {
	HRESULT hr;

	// Update the pipeline by sending commands to the commandqueue
	UpdatePipeline(); 

	// Create an array of command lists (only one command list here)
	ID3D12CommandList* ppCommandLists[] = { commandList };

	// Execute the array of command lists
	commandQueue->ExecuteCommandLists(_countof(ppCommandLists), ppCommandLists);

	// This command goes in at the end of our command queue. we will know when 
	// our command queue has finished because the fence value will be set to 
	// "fenceValue" from the GPU since the command queue is being executed on
	// the GPU
	hr = commandQueue->Signal(fence[frameIndex], fenceValue[frameIndex]);
	if (FAILED(hr)) {
		Running = false;
	}

	// Rresent the current backbuffer
	hr = swapChain->Present(0, 0);
	if (FAILED(hr)) {
		Running = false;
	}
}

// Release com ojects and clean up memory.
void Cleanup() {
	// Wait for the gpu to finish all frames
	for (int i = 0; i < frameBufferCount; ++i) {
		frameIndex = i;
		WaitForPreviousFrame();
	}

	// get swapchain out of full screen before exiting
	BOOL fs = false;
	if (swapChain->GetFullscreenState(&fs, NULL))
		swapChain->SetFullscreenState(false, NULL);

	SAFE_RELEASE(device);
	SAFE_RELEASE(swapChain);
	SAFE_RELEASE(commandQueue);
	SAFE_RELEASE(rtvDescriptorHeap);
	SAFE_RELEASE(commandList);

	for (int i = 0; i < frameBufferCount; ++i) {
		SAFE_RELEASE(renderTargets[i]);
		SAFE_RELEASE(commandAllocator[i]);
		SAFE_RELEASE(fence[i]);
	};

	SAFE_RELEASE(pipelineStateObject);
	SAFE_RELEASE(rootSignature);

	SAFE_RELEASE(depthStencilBuffer);
	SAFE_RELEASE(dsDescriptorHeap);

	delete timer;
	timer = NULL;

	delete mainModelLoader;
	mainModelLoader = NULL;

	delete mainUtil;
	mainUtil = NULL;

	delete mainCamera;
	mainCamera = NULL;

	for (int i = 0; i < frameBufferCount; ++i) {
		SAFE_RELEASE(constantBufferUploadHeaps[i]);
	};
}

// Wait until gpu is finished with command list. 
// Do not touch this funciton if you can
void WaitForPreviousFrame() {
	HRESULT hr;

	// Swap the current rtv buffer index so we draw on the correct buffer
	frameIndex = swapChain->GetCurrentBackBufferIndex();

	// If the current fence value is still less than "fenceValue", then we know 
	// the GPU has not finished executing the command queue since it has not 
	// reached the "commandQueue->Signal(fence, fenceValue)" command
	if (fence[frameIndex]->GetCompletedValue() < fenceValue[frameIndex]) {
		// We have the fence create an event which is signaled once the fence's 
		// current value is "fenceValue"
		hr = fence[frameIndex]->SetEventOnCompletion(
			fenceValue[frameIndex], 
			fenceEvent);
		if (FAILED(hr)) {
			Running = false;
		}

		// We will wait until the fence has triggered the event that it's 
		// current value has reached "fenceValue". once it's value
		// has reached "fenceValue", we know the command queue has 
		// finished executing
		WaitForSingleObject(fenceEvent, INFINITE);
	}
	// Increment fenceValue for next frame
	fenceValue[frameIndex]++;
}

//##############################################################################
//##############################################################################
//##############################################################################
// Main init resource objects function
//##############################################################################
//##############################################################################
//##############################################################################
void mainInit() {
	//==========================================================================
	// Main timer.
	//==========================================================================
	timer = new Timer();

	//==========================================================================
	// MyModelLoader object to load the models from files.
	//==========================================================================
	mainModelLoader = new MyModelLoader();
	//==========================================================================
	// Collection of utility function.
	//==========================================================================
	mainUtil = new Util();

	//==========================================================================
	// Init main Camera object.
	//==========================================================================
	mainCamera = new Camera(
		(float)Width, (float)Height, // Screen size
		45.0f,		// FOV
		0.1f,		// Near clipping
		1000.0f,	// Far clipping
		&XMVectorSet(0.0f, 5.0f, -15.0f, 0.0f),	// eye
		&XMVectorSet(0.0f, 0.0f, 0.0f, 0.0f),	// at 
		&XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f),	// up
		new MyModelLoader(), // For loading camera model
		NULL);	// Camera model file path
	mainCamera->cameraUpdate((float)Width, (float)Height, 45.0f, 0.1f, 1000.0f);

	//==========================================================================
	// Main data structure to hold the models to be initialized and kept.
	//==========================================================================
	mainModelsList = new MySpecialModelObjMtl *[100];
	// Number of models initialized in the mainModelsList data structure.
	numModelsInList = 0;
	
	//==========================================================================
	// Init models from file
	//==========================================================================
	model1 = mainModelLoader->myObjMtlLoader("\\modelloader_test_rectangle\\modelloader_test_rectangle\\modelloader_test_rectangle.obj");
	model2 = mainModelLoader->myObjMtlLoader("\\coordinateAxisOBJ.txt");
	model3 = mainModelLoader->myObjMtlLoader("\\myOBJ.txt");
	//model4 = mainModelLoader->myObjMtlLoader("\\low_poly_minion\\minions.obj");

	//==========================================================================
	// Init fonts from file
	//==========================================================================
	arialFont = new MyFont();

	//==========================================================================
	// Init animation from file
	//==========================================================================
	testAnim = mainModelLoader->myAnimationLoader("\\animation.txt");
	//_RPT1(0, "testAnim->getNumAnimationBones() : %d\n", testAnim->getNumAnimationBones());
	armature1 = mainModelLoader->myArmatureLoader("\\armature.txt");

	// Print to check the values loaded from file.
	// Actual file data:
	/*bn Bone
		<(1.0, 0.0, -0.0, -0.0)(-0.0, -0.1736, -0.9848, 0.1736)(-0.0, 0.9848, -0.1736, 0.0152)(0.0, 0.0, 0.0, 1.0)>
		<(1.0, 0.0, -0.0, -0.0)(-0.0, -0.1736, -0.9848, 0.1736)(-0.0, 0.9848, -0.1736, 0.0152)(0.0, 0.0, 0.0, 1.0)>
		<(1.0, 0.0, -0.0, -0.0)(-0.0, -0.1736, -0.9848, 0.1736)(-0.0, 0.9848, -0.1736, 0.0152)(0.0, 0.0, 0.0, 1.0)>
		<(1.0, 0.0, -0.0, -0.0)(-0.0, -0.1736, -0.9848, 0.1736)(-0.0, 0.9848, -0.1736, 0.0152)(0.0, 0.0, 0.0, 1.0)>
		bn Bone.001
		<(1.0, -0.0, 0.0, 0.0)(0.0, -0.0453, -0.999, 0.0)(0.0, 0.999, -0.0453, 1.0)(0.0, 0.0, 0.0, 1.0)>
		<(1.0, -0.0, 0.0, 0.0)(0.0, -0.1828, -0.9832, 0.0)(0.0, 0.9832, -0.1828, 1.0)(0.0, 0.0, 0.0, 1.0)>
		<(1.0, -0.0, 0.0, 0.0)(0.0, -0.3808, -0.9247, 0.0)(0.0, 0.9247, -0.3808, 1.0)(0.0, 0.0, 0.0, 1.0)>
		<(1.0, -0.0, 0.0, 0.0)(0.0, -0.5703, -0.8214, 0.0)(0.0, 0.8214, -0.5703, 1.0)(0.0, 0.0, 0.0, 1.0)>*/

	/*for (int i = 0; i < testAnim->getNumAnimationBones(); i++) {
		for (int j = 0; j < testAnim->getAnimationBones()->at(i)->getNumAnimationFrames(); j++) {
			_RPT1(0, "Test anim : (%f,%f,%f,%f)(%f,%f,%f,%f)(%f,%f,%f,%f)(%f,%f,%f,%f)\n",
				testAnim->getAnimationBones()->at(i)->getAnimationFrameAtIndex(j)->worldMatrix._11,
				testAnim->getAnimationBones()->at(i)->getAnimationFrameAtIndex(j)->worldMatrix._12,
				testAnim->getAnimationBones()->at(i)->getAnimationFrameAtIndex(j)->worldMatrix._13,
				testAnim->getAnimationBones()->at(i)->getAnimationFrameAtIndex(j)->worldMatrix._14,
				testAnim->getAnimationBones()->at(i)->getAnimationFrameAtIndex(j)->worldMatrix._21,
				testAnim->getAnimationBones()->at(i)->getAnimationFrameAtIndex(j)->worldMatrix._22,
				testAnim->getAnimationBones()->at(i)->getAnimationFrameAtIndex(j)->worldMatrix._23,
				testAnim->getAnimationBones()->at(i)->getAnimationFrameAtIndex(j)->worldMatrix._24,
				testAnim->getAnimationBones()->at(i)->getAnimationFrameAtIndex(j)->worldMatrix._31,
				testAnim->getAnimationBones()->at(i)->getAnimationFrameAtIndex(j)->worldMatrix._32,
				testAnim->getAnimationBones()->at(i)->getAnimationFrameAtIndex(j)->worldMatrix._33,
				testAnim->getAnimationBones()->at(i)->getAnimationFrameAtIndex(j)->worldMatrix._34,
				testAnim->getAnimationBones()->at(i)->getAnimationFrameAtIndex(j)->worldMatrix._41,
				testAnim->getAnimationBones()->at(i)->getAnimationFrameAtIndex(j)->worldMatrix._42,
				testAnim->getAnimationBones()->at(i)->getAnimationFrameAtIndex(j)->worldMatrix._43,
				testAnim->getAnimationBones()->at(i)->getAnimationFrameAtIndex(j)->worldMatrix._44);
		}
	}*/
}