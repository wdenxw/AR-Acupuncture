#include"stdafx.h"
#include"MarkFace.h"
#include <dlib/opencv.h>
#include <opencv2/highgui/highgui.hpp>
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/image_processing/render_face_detections.h>
#include <dlib/image_processing.h>
#include <opencv2/opencv.hpp> 
#include <dlib/gui_widgets.h>

using namespace dlib;
using namespace std;


void MarkFace::MarkPoints()
{
	try
	{
		cv::VideoCapture cap(0);
		image_window win;
		//cap.set(CV_CAP_PROP_FRAME_WIDTH, 640);  
		//cap.set(CV_CAP_PROP_FRAME_HEIGHT, 480);  
		// Load face detection and pose estimation models.  
		frontal_face_detector detector = get_frontal_face_detector();
		shape_predictor pose_model;
		deserialize("shape_predictor_68_face_landmarks.dat") >> pose_model;

		int count = 0;
		std::vector<rectangle> faces;
		// Grab and process frames until the main window is closed by the user.  
		while (!win.is_closed())
		{
			// Grab a frame  
			cv::Mat img, img_small;
			cap >> img;
			cv::resize(img, img_small, cv::Size(), 1.0 / RATIO, 1.0 / RATIO);

			cv_image<bgr_pixel> cimg(img);
			cv_image<bgr_pixel> cimg_small(img_small);

			// Detect faces   
			if (count++ % SKIP_FRAMES == 0) {
				faces = detector(cimg_small);
			}
			// Find the pose of each face.  
			std::vector<full_object_detection> shapes;
			for (unsigned long i = 0; i < faces.size(); ++i) {
				rectangle r(//�ڶ�Ӧ��ÿһ֡�а������ķ�Χ�þ��α�ʾ����
					(long)(faces[i].left() * RATIO),
					(long)(faces[i].top() * RATIO),
					(long)(faces[i].right() * RATIO),
					(long)(faces[i].bottom() * RATIO)
				);
				shapes.push_back(pose_model(cimg, r));//�ƶ���Ԫ�ص�ĩ�˲���ʲô��ģ�r����������⵽���������Σ�cimg��ͼƬָ�룿
													  //�淶�����õ��������
				int font_face = cv::FONT_HERSHEY_COMPLEX;
				double font_scale = 0.3;
				int thickness = 0.02;
				int baseline = 0;

				float ChengJiangX[5], ChengJiangY[5], YinTangX[5], YinTangY[5], RenZhongX[5], RenZhongY[5], YuYaoX[5], YuYaoY[5], WaiMingX[5], WaiMingY[5];
				float QiuHouX[5], QiuHouY[5], DiCangX[5], DiCangY[5], YingXiangX[5], YingXiangY[5];
				for (int k = 0; k < 68; ++k) {
					std::string text = std::to_string(k);
					cv::Size text_size = cv::getTextSize(text, font_face, font_scale, thickness, &baseline);
					//circle(img, cvPoint(shapes[i].part(k).x(), shapes[i].part(k).y()), 3, cv::Scalar(0, 0, 255), -1);//ͼƬ�����ĵ㣬�뾶������&��ɫ��-1������������꣬��㣩����opencv���㺯���������Ѩλ�Ϳ���ֱ������«��ư
					//cv::putText(img, text, cvPoint(shapes[i].part(k).x(), shapes[i].part(k).y()), font_face, font_scale, cv::Scalar(0, 255, 0), thickness, baseline);
					//��¼�н�Ѩ����
					if (k == 67)
					{
						ChengJiangX[0] = shapes[i].part(k).x();
						ChengJiangY[0] = shapes[i].part(k).y();

					}
					if (k == 8)
					{
						ChengJiangX[1] = shapes[i].part(k).x();
						ChengJiangY[1] = shapes[i].part(k).y();
					}
					//��¼ӡ��Ѩ����
					if (k == 21)
					{
						YinTangX[0] = shapes[i].part(k).x();
						YinTangY[0] = shapes[i].part(k).y();

					}
					if (k == 22)
					{
						YinTangX[1] = shapes[i].part(k).x();
						YinTangY[1] = shapes[i].part(k).y();
					}
					//��¼����Ѩ����
					if (k == 33)
					{
						RenZhongX[0] = shapes[i].part(k).x();
						RenZhongY[0] = shapes[i].part(k).y();

					}
					if (k == 61)
					{
						RenZhongX[1] = shapes[i].part(k).x();
						RenZhongY[1] = shapes[i].part(k).y();
					}
					//��¼����Ѩ�����꣨���Ѩ�ݴ˶�����
					if (k == 19)
					{
						YuYaoX[0] = shapes[i].part(k).x();
						YuYaoY[0] = shapes[i].part(k).y();

					}
					//��¼����Ѩ������
					if (k == 17)
					{
						WaiMingX[0] = shapes[i].part(k).x();
						WaiMingY[0] = shapes[i].part(k).y() + 10;

					}
					//��¼���Ѩ������
					if (k == 37)
					{
						QiuHouX[0] = shapes[i].part(k).x();
						QiuHouY[0] = shapes[i].part(k).y() + 30;

					}

					//��¼�ز�Ѩ������
					if (k == 48)
					{
						DiCangX[0] = shapes[i].part(k).x() - 5;
						DiCangY[0] = shapes[i].part(k).y();

					}
					//��¼ӭ��Ѩ������
					if (k == 31)
					{
						YingXiangX[0] = shapes[i].part(k).x() - 5;
						YingXiangY[0] = shapes[i].part(k).y();

					}

				}
				//�н�Ѩ�ı궨
				circle(img, cvPoint((ChengJiangX[0] + ChengJiangX[1]) / 2, (ChengJiangY[0] + ChengJiangY[1]) / 2), 3, cv::Scalar(0, 0, 255), -1);
				//ӡ��Ѩ�ı궨
				circle(img, cvPoint((YinTangX[0] + YinTangX[1]) / 2, (YinTangY[0] + YinTangY[1]) / 2), 3, cv::Scalar(0, 0, 255), -1);
				//����Ѩ�ı궨
				circle(img, cvPoint((RenZhongX[0] + RenZhongX[1]) / 2, (RenZhongY[0] + RenZhongY[1]) / 2), 3, cv::Scalar(0, 0, 255), -1);
				//����Ѩ�ı궨
				circle(img, cvPoint(YuYaoX[0], YuYaoY[0]), 3, cv::Scalar(0, 0, 255), -1);
				float GroundTrueX = (RenZhongX[0] + RenZhongX[1]) / 2;//�沿�е���յ�
				YuYaoX[1] = 2 * GroundTrueX - YuYaoX[0];
				YuYaoY[1] = YuYaoY[0];
				circle(img, cvPoint(YuYaoX[1], YuYaoY[1]), 3, cv::Scalar(0, 0, 255), -1);

				//���Ѩ�ı궨����������Ѩ������
				circle(img, cvPoint(YuYaoX[0], YuYaoY[0] - 20), 3, cv::Scalar(0, 0, 255), -1);
				circle(img, cvPoint(YuYaoX[1], YuYaoY[1] - 20), 3, cv::Scalar(0, 0, 255), -1);

				//����Ѩ�ı궨
				circle(img, cvPoint(WaiMingX[0], WaiMingY[0]), 3, cv::Scalar(0, 0, 255), -1);
				WaiMingX[1] = 2 * GroundTrueX - WaiMingX[0];
				WaiMingY[1] = WaiMingY[0];
				circle(img, cvPoint(WaiMingX[1], WaiMingY[1]), 3, cv::Scalar(0, 0, 255), -1);

				//���Ѩ�ı궨
				circle(img, cvPoint(QiuHouX[0], QiuHouY[0]), 3, cv::Scalar(0, 0, 255), -1);
				QiuHouX[1] = 2 * GroundTrueX - QiuHouX[0];
				QiuHouY[1] = QiuHouY[0];
				circle(img, cvPoint(QiuHouX[1], QiuHouY[1]), 3, cv::Scalar(0, 0, 255), -1);

				//����Ѩ�ı궨���������Ѩ������
				circle(img, cvPoint(QiuHouX[0] + 10, QiuHouY[0]), 3, cv::Scalar(0, 0, 255), -1);
				circle(img, cvPoint(QiuHouX[1] - 10, QiuHouY[1]), 3, cv::Scalar(0, 0, 255), -1);

				//�İ�Ѩ�ı궨��������󼰳���Ѩ������
				circle(img, cvPoint(QiuHouX[0] + 10, QiuHouY[0] + 10), 3, cv::Scalar(0, 0, 255), -1);
				circle(img, cvPoint(QiuHouX[1] - 10, QiuHouY[1] + 10), 3, cv::Scalar(0, 0, 255), -1);
				//�ز�Ѩ�ı궨
				circle(img, cvPoint(DiCangX[0], DiCangY[0]), 3, cv::Scalar(0, 0, 255), -1);
				DiCangX[1] = 2 * GroundTrueX - DiCangX[0];
				DiCangY[1] = DiCangY[0];
				circle(img, cvPoint(DiCangX[1], DiCangY[1]), 3, cv::Scalar(0, 0, 255), -1);
				//ӭ��Ѩ�ı궨
				circle(img, cvPoint(YingXiangX[0], YingXiangY[0]), 3, cv::Scalar(0, 0, 255), -1);
				YingXiangX[1] = 2 * GroundTrueX - YingXiangX[0];
				YingXiangY[1] = YingXiangY[0];
				circle(img, cvPoint(YingXiangX[1], YingXiangY[1]), 3, cv::Scalar(0, 0, 255), -1);
			}
			std::cout << "count:" << count << std::endl;
			// Display it all on the screen  
			win.clear_overlay();//���ǵ㣬�ߣ����ο�����ˢ�£�
			win.set_image(cimg);//������Ǵ���ͼƬ��һ�����ܣ�����ע�͵�
								//	win.add_overlay(render_face_detections(shapes));//���������֮�����״���ߣ�����ֱ��ע�͵�ֻ���������㣩

		}
	}
	catch (serialization_error& e)
	{
		cout << "You need dlib's default face landmarking model file to run this example." << endl;
		cout << "You can get it from the following URL: " << endl;
		cout << "   http://dlib.net/files/shape_predictor_68_face_landmarks.dat.bz2" << endl;
		cout << endl << e.what() << endl;
	}
	catch (exception& e)//�쳣������������ĳĳ�������ʾһ��press any key to exit֮���
	{
		cout << e.what() << endl;
	}
	system("pause");



}