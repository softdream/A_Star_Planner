#include "a_star.h"

int main()
{
	std::cout<<"------------------------- A STAR TEST -----------------------"<<std::endl;

	planner::AStar<float> a_star;	

	cv::Mat map = cv::Mat( 500, 500, CV_8UC1, cv::Scalar( 125 ) );
	
	for ( int i = 100; i < 400; i ++ ) {
		map.at<uchar>( i, 150 ) = 0;
		map.at<uchar>( i, 350 ) = 0;
	}

	for ( int j = 150; j < 350; j ++ ) {
		map.at<uchar>( 400, j ) = 0;
		map.at<uchar>( 100, j ) = 0;
	}

	//cv::imshow( "map", map );
	//cv::waitKey(0);

	a_star.setMap( map );

	planner::MapPoseType src( 120, 200 );
	planner::MapPoseType dst( 130, 200 );

	a_star.findPath( src, dst );
	
	auto path = a_star.getPath();
	for ( const auto& p : path ) {
		std::cout<<"( "<<p[0]<<", "<<p[1]<<" ) ";
	}
	std::cout<<std::endl;

	return 0;
}
