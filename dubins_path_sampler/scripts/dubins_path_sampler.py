#!/usr/bin/env python3

import rospy
from geometry_msgs.msg import PoseArray, Pose

import math
import dubins
from transforms3d.euler import euler2quat, quat2euler
import numpy as np
from shapely.geometry import LineString
from shapely.ops import unary_union

def callback(data: PoseArray):
	result = PoseArray()
	result.header = data.header

	line = LineString([p.position.x, p.position.y] for p in data.poses)
	distance_delta = 1.0
	distances = np.arange(0, line.length, distance_delta)[:-1]
	points = [line.interpolate(distance) for distance in distances] + [line.boundary[1]]
	for point in points:
		pose = Pose()
		pose.position.x = point.x
		pose.position.y = point.y
		result.poses.append(pose)

	# for pose_0, pose_1 in zip(data.poses, data.poses[1:]):


		# yaw_0 = math.atan2(pose_1.position.y - pose_0.position.y, pose_1.position.x - pose_1.position.y)
		# yaw_1 = math.atan2(pose_2.position.y - pose_1.position.y, pose_2.position.x - pose_1.position.y)

		# c_0 = (pose_0.position.x, pose_0.position.y, yaw_0)
		# c_1 = (pose_1.position.x, pose_1.position.y, yaw_1)

		# turning_radius = 3.0
		# step_size = 2.0

		# path = dubins.shortest_path(c_0, c_1, turning_radius)
		# confs, _ = path.sample_many(step_size)

		# for conf in confs:
		# 	pose = Pose()
		# 	pose.position.x = conf[0]
		# 	pose.position.y = conf[1]
		# 	pose.position.z = 0.0
		# 	q = euler2quat(0, 0, conf[2])
		# 	pose.orientation.x = q[0]
		# 	pose.orientation.y = q[1]
		# 	pose.orientation.x = q[2]
		# 	pose.orientation.w = q[3]
		# 	result.poses.append(pose)

	pub.publish(result)

rospy.init_node("dubins_path_sampler")
rospy.Subscriber("/waypoint_list", PoseArray, callback, queue_size=10)
pub = rospy.Publisher("/waypoint_list_dubins", PoseArray, queue_size=10, latch=True)
rospy.spin()
