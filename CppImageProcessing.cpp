// CppImageProcessing.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>

#include <opencv2/opencv.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/imgproc.hpp>


int main()
{
	// video processing tutorial from opencv.org
	std::string input_path = "G:/Video/7 Days to Die/7 Days to Die 2020.07.13 - 20.56.06.01.mp4";
	std::string output_path = "C:/Users/moriy/Downloads/video/video.mp4";
	cv::VideoCapture input(input_path);
	if (!input.isOpened()) {
		std::cout << "Could not open the input video: " << input_path << std::endl;
		return -1;
	}

	cv::VideoWriter output;  // init output video
	int fourcc = input.get(cv::CAP_PROP_FOURCC);
	//int fourcc = NULL;  // can make video
	cv::Size S = cv::Size((int)input.get(cv::CAP_PROP_FRAME_WIDTH) * 0.5, (int)input.get(cv::CAP_PROP_FRAME_HEIGHT) * 0.5);
	//cv::Size S;  // can't make video
	int fps = input.get(cv::CAP_PROP_FPS);
	//int fps = NULL;  // can't make video
	std::cout << "fourcc:" << fourcc << std::endl;
	std::cout << "fps:" << fps << std::endl;
	std::cout << "S:" << S << std::endl;
	output.open(output_path, fourcc, fps, S, false);

	if (!output.isOpened()) {
		std::cout << "Could not open the output video: " << output_path << std::endl;
		return -1;
	}

	cv::Mat src, res;  // show images
	for (int i=0; i < 1000; i++) {
		input >> src;
		if (src.empty()) break;

		cv::cvtColor(src, res, cv::COLOR_BGR2GRAY);
		cv::resize(res, res, S);
		output << res;
	}

	std::cout << "Finished writing." << std::endl;
	return 0;
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
