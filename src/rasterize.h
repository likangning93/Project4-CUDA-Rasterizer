/**
* @file      rasterize.h
* @brief     CUDA-accelerated rasterization pipeline.
* @authors   Skeleton code: Yining Karl Li, Kai Ninomiya
* @date      2012-2015
*/

#pragma once
#include <glm/glm.hpp>
#include <vector>
void addLights(std::vector<glm::vec3> &positions, std::vector<glm::vec3> &ambient,
	std::vector<glm::vec3> &diffuse, std::vector<glm::vec3> &specular);
void enableAA();
void rasterizeInit(int width, int height);
void rasterizeSetBuffers(
	int bufIdxSize, int *bufIdx,
	int vertCount, float *bufPos, float *bufNor, float *bufCol);
void rasterizeSetVariableBuffers();
void rasterize(uchar4 *pbo, glm::mat4 cameraMatrix);
void setupInstances(std::vector<glm::mat4> &modelTransform); // call after setup

void setupTiling(); // call after setup and setupInstances

void rasterizeFree();