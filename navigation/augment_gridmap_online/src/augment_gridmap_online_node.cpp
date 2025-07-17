#include <ros/ros.h>
#include <string.h>
#include "augment_gridmap_online/AugmentedGridMap.hpp"

std::string input_map = "map";
float obstacle_radius = 0.05;
bool add_static_obstacles = true;
std::string env_file_name = "/env_manage_yaml_path";
bool debug = false;

int main(int argc, char** argv)
{
	ros::init(argc, argv, "augment_gridmap_online_node");
	ros::NodeHandle nodeHandle("~");

    if(ros::param::has("~input_map"))
    	ros::param::get("~input_map", input_map);
    if(ros::param::has("~obstacle_radius"))
    	ros::param::get("~obstacle_radius", obstacle_radius);
    if(ros::param::has("~add_static_obstacles"))
    	ros::param::get("~add_static_obstacles", add_static_obstacles);
    if(ros::param::has("~env_file_name"))
    	ros::param::get("~env_file_name", env_file_name);
    if(ros::param::has("~debug"))
    	ros::param::get("~debug", debug);

	ros_augmented_gridmaps::AugmentedGridMap rosAgmentedGridmap(nodeHandle, input_map, obstacle_radius, debug, env_file_name, add_static_obstacles);

	ros::spin();
	return 0;
	}
