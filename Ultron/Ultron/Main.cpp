#include <sapi.h>
#include<iostream>
#include<string>
#include<opencv2/opencv.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/objdetect.hpp>

using namespace std;
using namespace cv;

void cameraCapture(Mat frame);
void faceWithImage(Mat image);

CascadeClassifier faceCascade;
string fcp;
int main()
{
	Mat image,frame;
	int a;
	ISpVoice* pVoice = NULL;
	VideoCapture cap;
	char str[1000];

	if (FAILED(::CoInitialize(NULL)))
		return FALSE;
	
	HRESULT hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void**)& pVoice);
	if (SUCCEEDED(hr))
	{
			cout << "\n                                                  Hello Everyone..!" << endl;
			hr = pVoice->Speak(L"\n Hello Everyone..!", SPF_IS_XML, NULL);
			cout << "                                       I'm Ultron The Image Processing Program." << endl;
			hr = pVoice->Speak(L"I'm Ultron The Image Processing Program.", SPF_IS_XML, NULL);
			do {
				hr = pVoice->Speak(L"Select the option from given menu.", SPF_IS_XML, NULL);
				cout << " 1. Detect face Using Image.\n 2. Detect Face Using Camera.\n 3. Exit."<<endl;
				cout << " Enter Your Choice : ";
				cin >> a;
				switch (a)
				{
				case 1:
					hr = pVoice->Speak(L"You have selected first option which is Detect face Using Image.", SPF_IS_XML, NULL);
					cout << "\n-->> Enter The Path Of Your Image" << endl;
					hr = pVoice->Speak(L"Enter The Path Of Your Image", SPF_IS_XML, NULL);
					cin >> str;
					image = imread(str);
					if (image.empty()) {
						cout << "Oops..! Image Is Not Found" << endl;
						hr = pVoice->Speak(L"Oops..! Image Is Not Found", SPF_IS_XML, NULL);
						return -1;
					}
					cout << " I Found Image..!!!";
					hr = pVoice->Speak(L"I Found Image..!!!", SPF_IS_XML, NULL);
					faceWithImage(image);
					cout << " Face Detected Successfully..."<<endl;
					hr = pVoice->Speak(L"Face Detected Successfully...", SPF_IS_XML, NULL);
					break;
				case 2:
					hr = pVoice->Speak(L"You have selected second option which is Detect face Using Image.", SPF_IS_XML, NULL);
					if (!cap.open(0))
					{
						cout<<" Sorry. I Unable To Access The Camera" << endl;
						hr = pVoice->Speak(L"Sorry. I Unable To Access The Camera...", SPF_IS_XML, NULL);
					}
					cap >> frame;
					if (frame.empty())
					{
						cout << "Sorry. I Unamble To Capture Image..." << endl;
						hr = pVoice->Speak(L"Sorry. I Unamble To Capture Image...", SPF_IS_XML, NULL);
					}
					cameraCapture(frame);
					cout << " Face Detected Successfully..." << endl;
					hr = pVoice->Speak(L"Face Detected Successfully...", SPF_IS_XML, NULL);
					break;
				case 3:
					void exit();
				default:
					cout << " Invalid Choice." << endl;
					break;
				}
			} while (a < 2);

			pVoice->Release();
			pVoice = NULL;
	}

	::CoUninitialize();
	return TRUE;
}
void faceWithImage(Mat image)
{
	fcp = "opencv-master/data/haarcascades/haarcascade_frontalface_alt.xml";
	faceCascade.load(fcp);
	vector<Rect> faces;
	faceCascade.detectMultiScale(image, faces);
	for (size_t i = 0; i < faces.size(); i++)
	{
		Point center(faces[i].x, faces[i].y);
		rectangle(image, center, Size(faces[i].x + faces[i].width, faces[i].y + faces[i].height),Scalar(0, 255, 0), 2, 4);
	}
	namedWindow("image", WINDOW_AUTOSIZE);
	imshow("image", image);
	waitKey(0);
}

void cameraCapture(Mat frame)
{
	fcp = "opencv-master/data/haarcascades/haarcascade_frontalface_alt.xml";
	faceCascade.load(fcp);


	vector<Rect> faces;
	faceCascade.detectMultiScale(frame, faces);
	for (size_t i = 0; i < faces.size(); i++)
	{
		Point center(faces[i].x, faces[i].y);
		rectangle(frame, center, Size(faces[i].x + faces[i].width, faces[i].y + faces[i].height), Scalar(0, 255, 0), 2, 4);
	}
	namedWindow("image", WINDOW_AUTOSIZE);
	imshow("image", frame);
	waitKey(0);
}