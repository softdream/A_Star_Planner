#include "a_star.h"

void initMap( cv::Mat& map )
{
	cv::circle( map, cv::Point( 250, 250 ), 40, cv::Scalar( 0 ), -1 );
}

void drawPath( cv::Mat& map, const std::vector<planner::MapPoseType>& path, const planner::MapPoseType& start, const planner::MapPoseType& dst )
{
	cv::circle( map, cv::Point( start[0], start[1] ), 3, cv::Scalar( 0 ), -1 );
	cv::circle( map, cv::Point( dst[0], dst[1] ), 3, cv::Scalar( 0 ), -1 );

	for ( const auto& pt : path ) {
		//map.at<uchar>( pt[0], pt[1] ) = 0;
		cv::circle( map, cv::Point( pt[0], pt[1] ), 3, cv::Scalar( 0 ), -1 );
	}

	cv::imshow( "map", map );
	cv::waitKey(0);
}


int main()
{
	std::cout<<"------------------------- A STAR TEST -----------------------"<<std::endl;

	planner::AStar<float> a_star;	

	cv::Mat map = cv::Mat( 500, 500, CV_8UC1, cv::Scalar( 125 ) );

	initMap( map );

	cv::imshow( "map", map );
	cv::waitKey(0);

	a_star.setMap( map );

	planner::MapPoseType src( 150, 150 );
	planner::MapPoseType dst( 250, 320 );

	a_star.findPath( src, dst );
	
	auto path = a_star.getPath();
	for ( const auto& p : path ) {
		std::cout<<"( "<<p[0]<<", "<<p[1]<<" ) ";
	}
	std::cout<<std::endl;

	drawPath( map, path, src, dst );

	return 0;
}
