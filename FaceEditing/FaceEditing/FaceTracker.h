#ifndef _FACETRACKER_H_
#define _FACETRACKER_H_


#include"Common.h"
#include"Tracker.h"

class clc_FaceTracker{

public:
	clc_FaceTracker():m_camera(NULL),m_stop(false){
	  
		m_camera = new cv::VideoCapture(CV_CAP_ANY);

		m_mode   = new  FACETRACKER::Tracker("./FaceTracker/model/face.tracker");

		m_Connectivity = FACETRACKER::IO::LoadCon("./FaceTracker/model/face.con");

		m_Triangulation = FACETRACKER::IO::LoadTri("./FaceTracker/model/face.tri");
	};
	~clc_FaceTracker(){};

	void Draw(cv::Mat& image,cv::Mat & shape,cv::Mat& con,cv::Mat& tri,cv::Mat& visi);
	void CameraTracker(void);


private:
	cv::Mat m_frame, m_gray;

	bool m_stop;
	cv::VideoCapture* m_camera;
	FACETRACKER::Tracker* m_mode;
	cv::Mat m_Connectivity;
	cv::Mat m_Triangulation;
};

void clc_FaceTracker::CameraTracker(void){

	std::vector<int> wSize1(1); wSize1[0] = 7;
	std::vector<int> wSize2(3); wSize2[0] = 11; wSize2[1] = 9; wSize2[2] = 7;
	int nIter = 5; double clamp = 3, fTol = 0.01;

	bool failed = true; int fnum = 0; double fps = 0; char sss[256]; std::string text;
	int64 t1, t0 = cv::getTickCount(); int fpd = -1;
	float scale = 1;

	if (m_camera != NULL && m_camera->isOpened())
	{
		while (!m_stop)
		{
			m_camera->read(m_frame);
		
			cv::resize(m_frame, m_frame, cv::Size(scale*m_frame.cols, scale*m_frame.rows));
			cv::flip(m_frame, m_frame, 1);
			cv::cvtColor(m_frame, m_gray, CV_BGR2GRAY);

			std::vector<int> wSize;

			if (failed)wSize = wSize2;
			else wSize = wSize1;

			if (m_mode->Track(m_gray, wSize, fpd, nIter, clamp, fTol, true) == 0){
				int idx = m_mode->_clm.GetViewIdx();
				failed = false;

				Draw(m_frame, m_mode->_shape, m_Connectivity, m_Triangulation, m_mode->_clm._visi[idx]);
			}
			else
			{
				/*cv::Mat R(m_frame, cv::Rect(0, 0, 150, 150));
				R = cv::Scalar(0, 0, 255);*/
				m_mode->FrameReset();
				failed = true;

			}

			// draw framerate
			//if (fnum >= 9){
			//	t1 = cv::getTickCount();
			//	fps = 10.0 / ((double(t1 - t0) / cv::getTickFrequency()) / 1e+6);
			//	t0 = t1; fnum = 0;
			//}
			//else fnum += 1;

			//sprintf(sss, "%d frames/sec", (int)round(fps));

			//text = sss;

			//cv::putText(m_frame, text, cv::Point(10, 20), CV_FONT_HERSHEY_SIMPLEX, 0.5, CV_RGB(255, 255, 255));

			cv::imshow("Face Tracker", m_frame);
			int c = cv::waitKey(10);
			if (c == 27) m_stop = true;
			else
			{
				m_mode->FrameReset();
			}

		}
	}

}

void clc_FaceTracker::Draw(cv::Mat &image, cv::Mat &shape, cv::Mat &con, cv::Mat &tri, cv::Mat &visi)
{
	int i, n = shape.rows / 2; cv::Point p1, p2; cv::Scalar c;

	//draw triangulation
	c = CV_RGB(0, 0, 0);
	for (i = 0; i < tri.rows; i++){
		if (visi.at<int>(tri.at<int>(i, 0), 0) == 0 ||
			visi.at<int>(tri.at<int>(i, 1), 0) == 0 ||
			visi.at<int>(tri.at<int>(i, 2), 0) == 0)continue;
		p1 = cv::Point(shape.at<double>(tri.at<int>(i, 0), 0),
			shape.at<double>(tri.at<int>(i, 0) + n, 0));
		p2 = cv::Point(shape.at<double>(tri.at<int>(i, 1), 0),
			shape.at<double>(tri.at<int>(i, 1) + n, 0));
		cv::line(image, p1, p2, c);
		p1 = cv::Point(shape.at<double>(tri.at<int>(i, 0), 0),
			shape.at<double>(tri.at<int>(i, 0) + n, 0));
		p2 = cv::Point(shape.at<double>(tri.at<int>(i, 2), 0),
			shape.at<double>(tri.at<int>(i, 2) + n, 0));
		cv::line(image, p1, p2, c);
		p1 = cv::Point(shape.at<double>(tri.at<int>(i, 2), 0),
			shape.at<double>(tri.at<int>(i, 2) + n, 0));
		p2 = cv::Point(shape.at<double>(tri.at<int>(i, 1), 0),
			shape.at<double>(tri.at<int>(i, 1) + n, 0));
		cv::line(image, p1, p2, c);
	}
	//draw connections
	c = CV_RGB(0, 0, 255);
	for (i = 0; i < con.cols; i++){
		if (visi.at<int>(con.at<int>(0, i), 0) == 0 ||
			visi.at<int>(con.at<int>(1, i), 0) == 0)continue;
		p1 = cv::Point(shape.at<double>(con.at<int>(0, i), 0),
			shape.at<double>(con.at<int>(0, i) + n, 0));
		p2 = cv::Point(shape.at<double>(con.at<int>(1, i), 0),
			shape.at<double>(con.at<int>(1, i) + n, 0));
		cv::line(image, p1, p2, c, 1);

	}

}
#endif

