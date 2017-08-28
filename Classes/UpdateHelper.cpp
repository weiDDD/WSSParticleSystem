#include "UpdateHelper.h"
using namespace pp;

static long getNowTime() {
	struct timeval now;
	gettimeofday(&now, NULL);
	return now.tv_usec;
}

UpdateHelper* UpdateHelper::instance = UpdateHelper::getInstance();
UpdateHelper* UpdateHelper::getInstance() {
	if (!instance) {
		instance = new UpdateHelper();
	}
	return instance;
}

void UpdateHelper::changePolygonToTriangleVec(std::vector<Vec2>& polygonPoints, std::vector<triangle>* triangleVec) {
	if (polygonPoints.size() == 3) {
		triangle triangleData;
		triangleData.point1 = polygonPoints[0];
		triangleData.point2 = polygonPoints[1];
		triangleData.point3 = polygonPoints[2];


		float a = triangleData.point3.x;
		float b = triangleData.point3.y;
		float d = triangleData.point2.x;
		float e = triangleData.point2.y;
		float f = triangleData.point1.x;
		float g = triangleData.point1.y;

		triangleData.areaSize = 0.5 * fabsf((d - a)*(g - b) - (f - a)*(e - b)); //0.5 * (a*e + d*g + b*f - f*e - a*g - d*b);

		triangleVec->push_back(triangleData);
		return;
	}

	// 凸点集合
	std::vector<Vec2> tuPointVec;
	std::vector<int> tuPointIndexVec;

	auto itor = polygonPoints.begin();
	int index = 0;
	while (itor != polygonPoints.end()) {
		// 除了正在判断的这个点的多边形
		std::vector<Vec2> otherPolygon;
		for (int i = 0; i < polygonPoints.size() - 1; ++i) {
			int indexTem = index + i + 1;
			while (indexTem > polygonPoints.size() - 1) {
				indexTem -= polygonPoints.size();
			}

			if (indexTem != index) {
				otherPolygon.push_back(polygonPoints[indexTem]);
			}
		}
		// 判断这个点是否在 除这个点以外其他点构成的多边形之内；方法：过这个点做水平它的直线，如果这条直线 与 多边形的交点 满足 在 判断点 的左右两侧均是奇数个，则在多边形内
		// 如果 这个点在 除这个点以外其他点构成的多边形之内，则是 凹点
		// 判断点
		Vec2 pointPos = (*itor);
		int leftJiaoPointNum = 0;
		int rightJiaoPointNum = 0;
		for (int i = 0; i < otherPolygon.size(); ++i) {
			// 一条边
			Vec2 point1 = otherPolygon[i];
			Vec2 point2;
			if (i == otherPolygon.size() - 1) {
				point2 = otherPolygon[0];
			}
			else {
				point2 = otherPolygon[i + 1];
			}
			// 判断这条边是否和 过 判断点的水平线相交
			if (fminf(point1.y, point2.y) <= pointPos.y && fmaxf(point1.y, point2.y) > pointPos.y) {
				// 相交之后 判断 相交点 是在 判断点的左右那一边
				float jiaoPointX;
				if (point2.x != point1.x) {
					float k = (point2.y - point1.y) / (point2.x - point1.x);
					float b = point2.y - k*point2.x;
					jiaoPointX = (pointPos.y - b) / k;
				}
				else {
					jiaoPointX = point2.x;
				}

				if (jiaoPointX < pointPos.x) {
					leftJiaoPointNum++;
				}
				else if (jiaoPointX > pointPos.x) {
					rightJiaoPointNum++;
				}
				else {
					leftJiaoPointNum++;
					rightJiaoPointNum++;
				}
			}
		}
		// 如果左右相交点为奇数 ，则是凹点
		if (leftJiaoPointNum % 2 == 1 && rightJiaoPointNum % 2 == 1) {
			//aoPointVec.push_back((*itor));
			//indexVec.push_back(index);
		}
		else {
			tuPointVec.push_back((*itor));
			tuPointIndexVec.push_back(index);
		}

		itor++;
		index++;

		otherPolygon.clear();
	}
	//找到了所有的凸点
	// 对所有的凸点进行判断，如果 这个多边形没有点在 这个凸点与其相邻点构成的三角形中，则将这个凸点和它相邻的点给切出来
	int tuPointSize = tuPointVec.size();
	for (int i = 0; i < tuPointSize; ++i) {
		int nowTuPointIndex = tuPointIndexVec[i];
		int leftPointIndex = nowTuPointIndex - 1;
		int rightPointIndex = nowTuPointIndex + 1;
		if (leftPointIndex < 0) {
			leftPointIndex = polygonPoints.size() + leftPointIndex;
		}
		if (rightPointIndex > polygonPoints.size() - 1) {
			rightPointIndex = rightPointIndex - polygonPoints.size();
		}
		// 点
		Vec2 nowTuPoint = polygonPoints[nowTuPointIndex];
		Vec2 tuPoint_left = polygonPoints[leftPointIndex];
		Vec2 tuPoint_right = polygonPoints[rightPointIndex];
		// 判断 这个多边形的点是否满足：没有一个点在这个三角形内
		bool isAllPointOut = true;
		for (int j = 0; j < polygonPoints.size(); j++) {
			if (j != nowTuPointIndex && j != leftPointIndex && j != rightPointIndex) {
				int leftJiaoPointNum = 0;
				int rightJiaoPointNum = 0;
				// 判断点
				Vec2 polygonPoint = polygonPoints[j];
				for (int k = 0; k < 3; k++) {
					Vec2 point1, point2;
					if (k == 0) {
						point1 = tuPoint_left;
						point2 = nowTuPoint;
					}
					else if (k == 1) {
						point1 = nowTuPoint;
						point2 = tuPoint_right;
					}
					else if (k == 2) {
						point1 = tuPoint_right;
						point2 = tuPoint_left;
					}

					// 判断三角形的 每条边是否和 过 判断点的水平线相交
					if (fminf(point1.y, point2.y) <= polygonPoint.y && fmaxf(point1.y, point2.y) > polygonPoint.y) {
						// 相交之后 判断 相交点 是在 判断点的左右那一边
						float jiaoPointX;
						if (point2.x != point1.x) {
							float k = (point2.y - point1.y) / (point2.x - point1.x);
							float b = point2.y - k*point2.x;
							jiaoPointX = (polygonPoint.y - b) / k;
						}
						else {
							jiaoPointX = point2.x;
						}

						if (jiaoPointX < polygonPoint.x) {
							leftJiaoPointNum++;
						}
						else if (jiaoPointX > polygonPoint.x) {
							rightJiaoPointNum++;
						}
						else {
							leftJiaoPointNum++;
							rightJiaoPointNum++;
						}
					}
				}
				// 点在里面
				if (leftJiaoPointNum % 2 == 1 && rightJiaoPointNum % 2 == 1) {
					isAllPointOut = false;
				}
				else {
					// 点在外面

				}

			}
		}
		// 如果所有的点都在外面，
		if (isAllPointOut) {
			std::vector<Vec2> polygon1;
			std::vector<Vec2> polygon2;

			polygon1.push_back(nowTuPoint);
			polygon1.push_back(tuPoint_left);
			polygon1.push_back(tuPoint_right);

			for (int j = 0; j < polygonPoints.size(); j++) {
				if (j != nowTuPointIndex) {
					polygon2.push_back(polygonPoints[j]);
				}
			}
			changePolygonToTriangleVec(polygon1, triangleVec);
			changePolygonToTriangleVec(polygon2, triangleVec);

			break;
		}

	}


}

// 更新粒子的运动
void UpdateHelper::updateParticleMove(particleProperty& p,float dt) {
	// 当前经过的时间 在全部总生命中的百分比
	float nowTimePrecent = (p.live - p.timeToLive) / p.live * 100;

	// 速度
	float speed = p.speed.getParticleVarietyValue(nowTimePrecent);

	// 加速度
	if (p.speed.pType == particlePropertyType::constValue) {
		float acc = p.acc.getParticleVarietyValue(nowTimePrecent); 
		p.speed.constValue += acc * dt;
		speed = p.speed.constValue;
	}
	// 移动角度
	float moveAngle = p.moveAngle.getParticleVarietyValue(nowTimePrecent); 

	// 移动角度为常值形式才能叠加 角速度
	if (p.moveAngle.pType == particlePropertyType::constValue) {
		// 角速度
		float moveAngleSpeed = p.angleSpeed.getParticleVarietyValue(nowTimePrecent); 
		p.moveAngle.constValue += moveAngleSpeed * dt;
		moveAngle = p.moveAngle.constValue;
	}

	p.speedX = speed * cosf(moveAngle / 180.0 * P_PI);
	p.speedY = speed * sinf(moveAngle / 180.0 * P_PI);
	// 重力 X
	float gravityX = p.gravityX.getParticleVarietyValue(nowTimePrecent);
	p.gravitySpeedX += gravityX*dt;

	// 重力 Y
	float gravityY = p.gravityY.getParticleVarietyValue(nowTimePrecent);
	p.gravitySpeedY += gravityY*dt;


	p.pos.x += p.speedX * dt + p.gravitySpeedX*dt;
	p.pos.y += p.speedY * dt + p.gravitySpeedY*dt;
	
}

////******************************************************************************************************************
float UpdateHelper::getValueFromEmitterVarietyValue(emitterVarietyValue& value , emitterFirePro& firePro) {
	if (value.pType == emitterPropertyType::oneConstant) {
		return value.constValue;
	}
	else if (value.pType == emitterPropertyType::moreConstant) {
		int size = (value.constValues).size();
		if (size == 0) {
			return 0;
		}
		int rand = floor(CCRANDOM_0_1() * size);
		if (rand == size) {
			rand = size - 1;
		}
		return (value.constValues)[rand];
	}
	else if (value.pType == emitterPropertyType::randBetweenTwoConst) {
		float minNum = (value.randConst1 > value.randConst2) ? value.randConst2 : value.randConst1;
		float maxNum = (value.randConst1 > value.randConst2) ? value.randConst1 : value.randConst2;
		float rand = CCRANDOM_0_1()*(maxNum - minNum) + minNum;

		return rand;

	}
	else if (value.pType == emitterPropertyType::curve) {
		// 发射器中的曲线类型，横坐标为发射器的周期
		// 当前的时间
		float nowTimeInDuration = firePro._elapsed;
		// 设置KB
		if (!value.isSetCurveKB) {
			int kbSize = value.curveKB.size();
			if (kbSize > 0) {
				value.curveKB.clear();
				kbSize = 0;
			}
			if (kbSize == 0) {
				int size = (value.curvePoints).size();
				for (int i = 0; i < size - 1; ++i) {
					Vec3 left = (value.curvePoints)[i];
					Vec3 right = (value.curvePoints)[i + 1];
					float k = (right.y - left.y) / (right.x - left.x);
					float b = left.y - k*left.x;
					value.curveKB.push_back(Vec2(k, b));
				}
			}
			// 上下随机线的KB
			int randUpKbSize = value.randUpCurveKB.size();
			if (randUpKbSize > 0) {
				value.randUpCurveKB.clear();
				randUpKbSize = 0;
			}
			if (randUpKbSize == 0) {

				int size = (value.curvePoints).size();
				for (int i = 0; i < size - 1; ++i) {
					Vec3 left = (value.curvePoints)[i];
					Vec3 right = (value.curvePoints)[i + 1];
					float k = (right.y + right.z - left.y - left.z) / (right.x - left.x);
					float b = left.y + left.z - k*left.x;
					value.randUpCurveKB.push_back(Vec2(k, b));
				}
			}
			//
			int randDownKbSize = value.randDownCurveKB.size();
			if (randDownKbSize > 0) {
				value.randDownCurveKB.clear();
				randDownKbSize = 0;
			}
			if (randDownKbSize == 0) {

				int size = (value.curvePoints).size();
				for (int i = 0; i < size - 1; ++i) {
					Vec3 left = (value.curvePoints)[i];
					Vec3 right = (value.curvePoints)[i + 1];
					float k = (right.y - right.z - left.y + left.z) / (right.x - left.x);
					float b = left.y - left.z - k*left.x;
					value.randDownCurveKB.push_back(Vec2(k, b));
				}
			}

			value.isSetCurveKB = true;
		}

		//获取曲线数据
		int size = ((value).curvePoints).size();
		for (int i = 0; i < size - 1; ++i) {
			Vec3 pos = ((value).curvePoints)[i + 1];
			float inDurationX = nowTimeInDuration / firePro._duration;
			if (inDurationX < pos.x) {
				//float k = (*(value).curveKB).at(i).x;
				//float b = (*(value).curveKB).at(i).y;
				//float realPY = k*nowTimeInDuration + b;
				// 根据发射周期时间点对应的上下的随机线的值来 设置 发射开始时的粒子属性
				float upK = ((value).randUpCurveKB)[i].x;
				float upB = ((value).randUpCurveKB)[i].y;
				float upY = upK*inDurationX + upB;

				float downK = ((value).randDownCurveKB)[i].x;
				float downB = ((value).randDownCurveKB)[i].y;
				float downY = downK*inDurationX + downB;

				return downY + CCRANDOM_0_1() * (upY - downY);
			}
		}

		return 0;
	}
	else {
		return 0;
	}
}

// 设置粒子生命周期内的属性
void UpdateHelper::setParticleVarietyValue(particleVarietyValue &pValue, emitterVarietyValue &eValue, float pLife) {
	if (eValue.pType == emitterPropertyType::curve)
	{
		pValue.pType = particlePropertyType::curve;
		pValue.curvePoints.clear();
		pValue.isSetCurveKB = false;

		int index = 0;

		Vec3* itor = &eValue.curvePoints[0];
		int size = eValue.curvePoints.size();
		pValue.curvePoints.reserve(size);
		for (itor; index < size; ++itor) {
			float z = itor->z;
			pValue.curvePoints.emplace_back(Vec2( itor->x, itor->y - z + CCRANDOM_0_1() * 2 * z));
			++index;
		}


		/*auto itor = eValue.curvePoints.begin();
		while (itor != eValue.curvePoints.end()) {
			pValue.curvePoints.push_back(Vec2((*itor).x, (*itor).y - (*itor).z + CCRANDOM_0_1() * 2 * (*itor).z));
			
			++index;
			++itor;
		}*/


		pValue.curvePointFirstPoint = &pValue.curvePoints[0];
		pValue.curvePointSize = pValue.curvePoints.size();
		pValue.curveLeftPointX = pValue.curvePoints[0].x;
		pValue.curveRightPointX = pValue.curvePoints[pValue.curvePoints.size()-1].x;

	}
	else {

	}
}

///////////////--------------------------
Color3B UpdateHelper::getValueFromEmitterVarietyColorValue(emitterColorValue& value , emitterFirePro& firePro) {
	if (value.pType == emitterPropertyType::oneConstant) {
		return value.constColor;
	}
	else if (value.pType == emitterPropertyType::moreConstant) {
		int size = (value.constColors).size();
		if (size == 0) {
			return Color3B(255, 255, 255);
		}
		int rand = floor(CCRANDOM_0_1() * size);
		if (rand == size) {
			rand = size - 1;
		}
		return (value.constColors)[rand];
	}
	else if (value.pType == emitterPropertyType::randBetweenTwoConst) {
		float minR = (value.randColor1.r > value.randColor2.r) ? value.randColor2.r : value.randColor1.r;
		float maxR = (value.randColor1.r > value.randColor2.r) ? value.randColor1.r : value.randColor2.r;
		float randR = CCRANDOM_0_1()*(maxR - minR) + minR;
		float minG = (value.randColor1.g > value.randColor2.g) ? value.randColor2.g : value.randColor1.g;
		float maxG = (value.randColor1.g > value.randColor2.g) ? value.randColor1.g : value.randColor2.g;
		float randG = CCRANDOM_0_1()*(maxG - minG) + minG;
		float minB = (value.randColor1.b > value.randColor2.b) ? value.randColor2.b : value.randColor1.b;
		float maxB = (value.randColor1.b > value.randColor2.b) ? value.randColor1.b : value.randColor2.b;
		float randB = CCRANDOM_0_1()*(maxB - minB) + minB;

		return Color3B(randR, randG, randB);

	}
	else if (value.pType == emitterPropertyType::curve) {
		// 当前的时间
		float nowTimeInDuration = firePro._elapsed;
		float inDurationX = nowTimeInDuration / firePro._duration;

		if (value.curveColors.size() > 0) {
			std::vector<colorCurvePoint> curveColorsTem;

			colorCurvePoint leftColorPoint;
			leftColorPoint.x = 0;
			leftColorPoint.colorY = value.curveColors[0].colorY;
			curveColorsTem.push_back(leftColorPoint);

			auto itor = value.curveColors.begin();
			while (itor != value.curveColors.end()) {
				curveColorsTem.push_back((*itor));
				itor++;
			}
			colorCurvePoint rightColorPoint;
			rightColorPoint.x = 1;
			rightColorPoint.colorY = value.curveColors[value.curveColors.size() - 1].colorY;
			curveColorsTem.push_back(rightColorPoint);

			int curveColorSize = curveColorsTem.size();
			for (int i = 0; i < curveColorSize; ++i) {
				if (inDurationX < curveColorsTem[i].x) {
					float leftX = curveColorsTem[i - 1].x;
					float rightX = curveColorsTem[i].x;
					Color3B leftColor = curveColorsTem[i - 1].colorY;
					Color3B rightColor = curveColorsTem[i].colorY;
					Vec3 leftRandColor = curveColorsTem[i - 1].colorRand;
					Vec3 rightRandColor = curveColorsTem[i].colorRand;

					if (i == 1) {
						return rightColor;
					}
					if (i == curveColorSize - 1) {
						return leftColor;
					}
					float precent = (inDurationX - leftX) / (rightX - leftX);
					Color3B realLeftColor = Color3B(leftColor.r - leftRandColor.x + CCRANDOM_0_1() * 2 * leftRandColor.x,
						leftColor.g - leftRandColor.y + CCRANDOM_0_1() * 2 * leftRandColor.y,
						leftColor.b - leftRandColor.z + CCRANDOM_0_1() * 2 * leftRandColor.z);
					Color3B realRightColor = Color3B(rightColor.r - rightRandColor.x + CCRANDOM_0_1() * 2 * rightRandColor.x,
						rightColor.g - rightRandColor.y + CCRANDOM_0_1() * 2 * rightRandColor.y,
						rightColor.b - rightRandColor.z + CCRANDOM_0_1() * 2 * rightRandColor.z);

					Color3B realReturnColor = Color3B(realLeftColor.r + precent * (realRightColor.r - realLeftColor.r),
						realLeftColor.g + precent * (realRightColor.g - realLeftColor.g),
						realLeftColor.b + precent * (realRightColor.b - realLeftColor.b));
					return realReturnColor;
				}

			}

		}

		return Color3B::WHITE;
	}
	else {
		return Color3B::WHITE;
	}
}

// 设置粒子生命周期内的 颜色 属性
void UpdateHelper::setParticleVarietyColorValue(particleColorValue &pValue, emitterColorValue &eValue, float pLife) {
	
	if (eValue.pType == emitterPropertyType::curve)
	{
		pValue.pType = particlePropertyType::curve;
		pValue.curveColors.clear();

		colorCurvePoint* itor = &eValue.curveColors[0];
		int size = eValue.curveColors.size();
		pValue.curveColors.reserve(size);
		int index = 0;
		for (itor; index < size; ++itor) {
			colorCurvePoint colorPoint;
			colorPoint.x = itor->x;
			colorPoint.colorY = itor->colorY;
			colorPoint.colorRand = itor->colorRand;

			pValue.curveColors.push_back(colorPoint);

			++index;
		}

		/*auto itor = eValue.curveColors.begin();
		while (itor != eValue.curveColors.end()) {
			colorCurvePoint colorPoint;
			colorPoint.x = (*itor).x;
			colorPoint.colorY = (*itor).colorY;
			colorPoint.colorRand = (*itor).colorRand;

			pValue.curveColors.push_back(colorPoint);
			++itor;
		}*/


		pValue.isSetRealColorY = false;

		pValue.curveColorsFirstPtr = &pValue.curveColors[0];
		pValue.curveColorsSize = pValue.curveColors.size();
		pValue.curveLeftPointX = pValue.curveColors[0].x;
		pValue.curveRightPointX = pValue.curveColors[pValue.curveColorsSize -1].x;
	}
	else {

	}
}

void UpdateHelper::initParticlePro(ParticleEmitter* father, emitterFirePro& firePro, particleProperty* particle) {

	//Vec2 emitterPos = this->convertToWorldSpace(Vec2::ZERO);
	Vec2 emitterPos = Vec2(0, 0);
	if (firePro._positionType == positionType::RELATIVE) {
		emitterPos = Vec2(0, 0);
	}
	else if (firePro._positionType == positionType::FREE) {
		emitterPos = father->convertToWorldSpace(Vec2::ZERO);

		emitterPos = father->runningLayer->convertToNodeSpace(emitterPos);
	}


	//位置
	if (firePro._fireArea.fAreaType == fireAreaType::rect) {

		float diffX = (firePro._fireArea.outRect.width - firePro._fireArea.inRect.width) / 2;
		float diffY = (firePro._fireArea.outRect.height - firePro._fireArea.inRect.height) / 2;
		float randDir = CCRANDOM_0_1();
		float rx = 0;
		float ry = 0;

		if (randDir <= 0.25) {
			//left
			rx = emitterPos.x - firePro._fireArea.outRect.width / 2 + CCRANDOM_0_1()*diffX;
			ry = emitterPos.y - firePro._fireArea.outRect.height / 2 + CCRANDOM_0_1()* firePro._fireArea.outRect.height;
			particle->startToCenterAngle = 180;
		}
		else if (randDir <= 0.5 && randDir > 0.25) {
			//right
			rx = emitterPos.x + firePro._fireArea.outRect.width / 2 - CCRANDOM_0_1()*diffX;
			ry = emitterPos.y - firePro._fireArea.outRect.height / 2 + CCRANDOM_0_1()* firePro._fireArea.outRect.height;
			particle->startToCenterAngle = 0;
		}
		else if (randDir <= 0.75 && randDir > 0.5) {
			//up
			rx = emitterPos.x - firePro._fireArea.outRect.width / 2 + CCRANDOM_0_1()*firePro._fireArea.outRect.width;
			ry = emitterPos.y + firePro._fireArea.outRect.height / 2 - CCRANDOM_0_1()*diffY;
			particle->startToCenterAngle = 90;
		}
		else {
			//down
			rx = emitterPos.x - firePro._fireArea.outRect.width / 2 + CCRANDOM_0_1()*firePro._fireArea.outRect.width;
			ry = emitterPos.y - firePro._fireArea.outRect.height / 2 + CCRANDOM_0_1()*diffY;
			particle->startToCenterAngle = 270;
		}

		particle->pos.x = rx;
		particle->pos.y = ry;
		particle->startPos = particle->pos;
	}
	else if (firePro._fireArea.fAreaType == fireAreaType::circle) {
		float randAngle = CCRANDOM_0_1() * 360;
		float randRadius = firePro._fireArea.inCircleRadius + CCRANDOM_0_1() * (firePro._fireArea.outCircleRadius - firePro._fireArea.inCircleRadius);
		Vec2 randPos = Vec2(emitterPos.x + randRadius * cosf(randAngle / 180 * P_PI), emitterPos.y + randRadius * sinf(randAngle / 180 * P_PI));
		particle->pos.x = randPos.x;
		particle->pos.y = randPos.y;
		particle->startPos = particle->pos;
		particle->startToCenterAngle = randAngle;
	}
	else if (firePro._fireArea.fAreaType == fireAreaType::polygon) {
		// 原理：将多边形 分割 成n个三角形，再随机选一个三角形，再计算一个在这个三角形中的随机点
		// 详细原理：任意凹多边形划分为n个三角形。 首先找到凹多边形的所有凹点，如果只有一个凹点则过凹点对其他不相邻的点连线形成三角形，如果有多个凹点，将凹点连线划分为n个多边形，再对这些多边形 重复上面的步骤
		// 参考: https://www.zhihu.com/question/41356737/answer/90644562
		// 如果不是边缘发射
		if (!firePro._fireArea.isEdgeFire && firePro._fireArea.polygonPoints.size() >= 3) {
			float randVar = CCRANDOM_0_1();
			if (randVar == 1) {
				randVar = 0.99f;  // 防止当 randVar = 1时出现的bug
			}

			if (firePro._fireArea.polygonTriangleVec.size() > 0) {
				// 按三角形的面积大小来给予一定的随机量
				//所有三角形的面积
				float allAreaSize = 0;
				for (int i = 0; i < firePro._fireArea.polygonTriangleVec.size(); ++i) {
					allAreaSize += firePro._fireArea.polygonTriangleVec[i].areaSize;
				}
				//
				float nowAreaSize = 0;
				int randTriangle = 0;
				for (int i = 0; i < firePro._fireArea.polygonTriangleVec.size(); ++i) {
					nowAreaSize += firePro._fireArea.polygonTriangleVec[i].areaSize / allAreaSize * 100;
					if (randVar * 100 <= nowAreaSize) {
						randTriangle = i;
						break;
					}
				}

				triangle triangleData = firePro._fireArea.polygonTriangleVec[randTriangle];
				Vec2 PointA = triangleData.point1;
				Vec2 PointB = triangleData.point2;
				Vec2 PointC = triangleData.point3;

				Vec2 AB = Vec2(PointB.x - PointA.x, PointB.y - PointA.y);
				Vec2 AC = Vec2(PointC.x - PointA.x, PointC.y - PointA.y);
				float randX = CCRANDOM_0_1();
				float randY = CCRANDOM_0_1();

				float rx, ry;
				if (randX + randY > 1) {
					rx = 1 - randX;
					ry = 1 - randY;
				}
				else if (randX + randY <= 1) {
					rx = randX;
					ry = randY;
				}
				Vec2 randPoint = Vec2(PointA.x + rx * AB.x + ry * AC.x, PointA.y + rx * AB.y + ry * AC.y);
				particle->pos.x = emitterPos.x + randPoint.x;
				particle->pos.y = emitterPos.y + randPoint.y;
				particle->startPos = particle->pos;
				particle->startToCenterAngle = Vec2(particle->pos.x - emitterPos.x, particle->pos.y - emitterPos.y).getAngle() / P_PI * 180;
			}
		}
		else if (firePro._fireArea.isEdgeFire && firePro._fireArea.polygonPoints.size() >= 3) {
			// 边缘发射
			// 找到一个随机边
			// 按 线段长度 来给予一定的随机量
			float randVar = CCRANDOM_0_1();
			if (randVar == 1) {
				randVar = 0.99f;
			}
			//assert(firePro._fireArea.polygonPoints.size() == firePro._fireArea.polygonLinesDis.size() , "init particle , polygonPoints size is not equal polygonLinesDis size !");
			if (firePro._fireArea.polygonPoints.size() != firePro._fireArea.polygonLinesDis.size()) {
				return;
			}

			// 所有线段的总长度
			float allLength = 0;
			int disSize = firePro._fireArea.polygonLinesDis.size();
			for (int i = 0; i < disSize; ++i) {
				allLength += firePro._fireArea.polygonLinesDis[i];
			}

			float nowLength = 0;
			int randEdge = 0;  // 1 ~ edgeNum
			for (int i = 0; i < disSize; ++i) {
				nowLength += firePro._fireArea.polygonLinesDis[i];
				if (randVar * 100 <= nowLength / allLength * 100) {
					randEdge = i + 1;
					break;
				}
			}

			//int randEdge = floorf(randVar * (firePro._fireArea.polygonPoints.size())) + 1; // 1 ~ edgeNum
			Vec2 pointA;
			Vec2 pointB;
			if (randEdge == firePro._fireArea.polygonPoints.size()) {
				pointA = firePro._fireArea.polygonPoints[randEdge - 1];
				pointB = firePro._fireArea.polygonPoints[0];
			}
			else {
				pointA = firePro._fireArea.polygonPoints[randEdge - 1];
				pointB = firePro._fireArea.polygonPoints[randEdge];
			}
			float dis = pointA.getDistance(pointB);
			float randX = pointA.x + CCRANDOM_0_1() * dis;
			float randY = pointA.y - firePro._fireArea.edgeFireWidth / 2 + CCRANDOM_0_1() * firePro._fireArea.edgeFireWidth;
			float angleOffset = Vec2(pointB.x - pointA.x, pointB.y - pointA.y).getAngle() / P_PI * 180;

			// 按角度转过去
			float nowAngle = Vec2(randX - pointA.x, randY - pointA.y).getAngle() / P_PI * 180;
			float nowDis = Vec2(randX, randY).getDistance(pointA);
			Vec2 realPoint = Vec2(pointA.x + nowDis * cosf((nowAngle + angleOffset) / 180.0 * P_PI), pointA.y + nowDis * sinf((nowAngle + angleOffset) / 180.0 * P_PI));
			particle->pos.x = emitterPos.x + realPoint.x;
			particle->pos.y = emitterPos.y + realPoint.y;
			particle->startPos = particle->pos;
			particle->startToCenterAngle = Vec2(particle->pos.x - emitterPos.x, particle->pos.y - emitterPos.y).getAngle() / 3.14 * 180;
		}


	}
	else if (firePro._fireArea.fAreaType == fireAreaType::lines) {
		// 边缘发射
		// 找到一个随机边
		float randVar = CCRANDOM_0_1();
		if (randVar == 1) {
			randVar = 0.99f;
		}

		CCASSERT(firePro._fireArea.linePoints.size() - 1 == firePro._fireArea.lineLinesDis.size(), "init particle , linePoints size - 1 is not equal lineLinesDis size !");


		// 所有线段的总长度
		float allLength = 0;
		int disSize = firePro._fireArea.lineLinesDis.size();
		for (int i = 0; i < disSize; ++i) {
			allLength += firePro._fireArea.lineLinesDis[i];
		}

		float nowLength = 0;
		int randEdge = 0;  // 1 ~ edgeNum
		for (int i = 0; i < disSize; ++i) {
			nowLength += firePro._fireArea.lineLinesDis[i];
			if (randVar * 100 <= nowLength / allLength * 100) {
				randEdge = i + 1;
				break;
			}
		}

		//int randEdge = floorf(randVar * (firePro._fireArea.linePoints.size() - 1)) + 1; // 1 ~ edgeNum - 1
		Vec2 pointA;
		Vec2 pointB;

		pointA = firePro._fireArea.linePoints[randEdge - 1];
		pointB = firePro._fireArea.linePoints[randEdge];

		float dis = pointA.getDistance(pointB);
		float randX = pointA.x + CCRANDOM_0_1() * dis;
		float randY = pointA.y - firePro._fireArea.edgeFireWidth / 2 + CCRANDOM_0_1() * firePro._fireArea.edgeFireWidth;
		float angleOffset = Vec2(pointB.x - pointA.x, pointB.y - pointA.y).getAngle() / P_PI * 180;

		// 按角度转过去
		float nowAngle = Vec2(randX - pointA.x, randY - pointA.y).getAngle() / 3.14 * 180;
		float nowDis = Vec2(randX, randY).getDistance(pointA);
		Vec2 realPoint = Vec2(pointA.x + nowDis * cosf((nowAngle + angleOffset) / 180.0 * P_PI), pointA.y + nowDis * sinf((nowAngle + angleOffset) / 180.0 * P_PI));
		particle->pos.x = emitterPos.x + realPoint.x;
		particle->pos.y = emitterPos.y + realPoint.y;
		particle->startPos = particle->pos;
		particle->startToCenterAngle = Vec2(particle->pos.x - emitterPos.x, particle->pos.y - emitterPos.y).getAngle() / 3.14 * 180;
	}
	else {
		particle->pos.x = emitterPos.x;
		particle->pos.y = emitterPos.y;
		particle->startPos = particle->pos;
		particle->startToCenterAngle = 0;
	}

	if (firePro._positionType == positionType::FREE ) {
		float rotation = father->getRotation();
		if (rotation != 0) {
			Vec2 offsetPos = Vec2(particle->pos.x - emitterPos.x, particle->pos.y - emitterPos.y);

			float angle = offsetPos.getAngle() / P_PI * 180;
			float dis = offsetPos.getDistance(Vec2(0, 0));
			Vec2 newPos = Vec2(emitterPos.x + dis*cosf((-rotation + angle) / 180 * M_PI), emitterPos.y + dis*sinf((-rotation + angle) / 180 * M_PI));
			particle->pos = newPos;

		}
	}

	particle->emitterPos = emitterPos;

	float startAngle = Vec2(particle->pos.x - emitterPos.x, particle->pos.y - emitterPos.y).getAngle() / P_PI * 180;
	float emitterRotation = father->getRotation();
	float emitterDis = particle->pos.getDistance(particle->emitterPos);
	// 计算出这个粒子相对于 particleEmitter 旋转后，其所在位置的偏移量。
	if (emitterRotation == 0) {
		particle->rotationPosOffset = Vec2(0, 0);
	}
	else {
		particle->rotationPosOffset = Vec2(emitterDis*cosf((startAngle - emitterRotation) / 180 * P_PI) - (particle->startPos.x - particle->emitterPos.x),
			emitterDis*sinf((startAngle - emitterRotation) / 180 * P_PI) - (particle->startPos.y - particle->emitterPos.y));
	}

	// 处理锚点
	particle->anchorPoint = firePro._texAnchorPoint;

	// 生命
	particle->live = this->getValueFromEmitterVarietyValue(firePro._life, firePro);
	particle->timeToLive = particle->live;

	//////---------------------速度
	// 设置粒子生命周期内的 值
	if (firePro._moveSpeedOfLife.pType == emitterPropertyType::curve && firePro._moveSpeedOfLife.curvePoints.size() >= 2) {
		this->setParticleVarietyValue(particle->speed, firePro._moveSpeedOfLife, particle->timeToLive);
	}
	else {
		particle->speed.pType = particlePropertyType::constValue;
		particle->speed.constValue = this->getValueFromEmitterVarietyValue(firePro._startMoveSpeed, firePro);
	}

	//////---------------------加速度
	if (firePro._moveAccOfLife.pType == emitterPropertyType::curve && firePro._moveAccOfLife.curvePoints.size() >= 2) {
		this->setParticleVarietyValue(particle->acc, firePro._moveAccOfLife, particle->timeToLive);
	}
	else {
		particle->acc.pType = particlePropertyType::constValue;
		particle->acc.constValue = this->getValueFromEmitterVarietyValue(firePro._startMoveAcc, firePro);
	}

	//////---------------------移动角度
	if (firePro._moveAngleOfLife.pType == emitterPropertyType::curve && firePro._moveAngleOfLife.curvePoints.size() >= 2) {
		this->setParticleVarietyValue(particle->moveAngle, firePro._moveAngleOfLife, particle->timeToLive);
	}
	else {
		particle->moveAngle.pType = particlePropertyType::constValue;
		particle->moveAngle.constValue = this->getValueFromEmitterVarietyValue(firePro._startMoveAngle, firePro);
	}
	// 如果是本地发射角度，则转化角度
	if (firePro._angleType == fireAngleType::local) {
		if (particle->moveAngle.pType == particlePropertyType::constValue) {
			particle->moveAngle.constValue += particle->startToCenterAngle;
		}
		else if (particle->moveAngle.pType == particlePropertyType::curve) {
			for (int i = 0; i < particle->moveAngle.curvePoints.size(); ++i) {
				particle->moveAngle.curvePoints[i].y += particle->startToCenterAngle;
			}
		}
	}

	if (firePro._positionType == positionType::FREE) {
		float rotation = father->getRotation();
		if (rotation != 0) {
			if (particle->moveAngle.pType == particlePropertyType::constValue) {
				particle->moveAngle.constValue -= rotation;
			}
			else if (particle->moveAngle.pType == particlePropertyType::curve) {
				for (int i = 0; i < particle->moveAngle.curvePoints.size(); ++i) {
					particle->moveAngle.curvePoints[i].y -= rotation;
				}
			}
		}
	}

	//////---------------------角速度
	if (firePro._moveAngleSpeedOfLife.pType == emitterPropertyType::curve && firePro._moveAngleSpeedOfLife.curvePoints.size() >= 2) {
		this->setParticleVarietyValue(particle->angleSpeed, firePro._moveAngleSpeedOfLife, particle->timeToLive);
	}
	else {
		particle->angleSpeed.pType = particlePropertyType::constValue;
		particle->angleSpeed.constValue = this->getValueFromEmitterVarietyValue(firePro._startMoveAngleSpeed, firePro);
	}

	//////---------------------重力X
	if (firePro._gravityXOfLife.pType == emitterPropertyType::curve && firePro._gravityXOfLife.curvePoints.size() >= 2) {
		this->setParticleVarietyValue(particle->gravityX, firePro._gravityXOfLife, particle->timeToLive);
	}
	else {
		particle->gravityX.pType = particlePropertyType::constValue;
		particle->gravityX.constValue = this->getValueFromEmitterVarietyValue(firePro._startGravityX, firePro);
	}


	//////---------------------重力Y
	if (firePro._gravityYOfLife.pType == emitterPropertyType::curve && firePro._gravityYOfLife.curvePoints.size() >= 2) {
		this->setParticleVarietyValue(particle->gravityY, firePro._gravityYOfLife, particle->timeToLive);
	}
	else {
		particle->gravityY.pType = particlePropertyType::constValue;
		particle->gravityY.constValue = this->getValueFromEmitterVarietyValue(firePro._startGravityY, firePro);
	}

	
	//////---------------------大小
	if (firePro._parType == parType::render) {
		if (firePro._sizeOfLife.pType == emitterPropertyType::curve && firePro._sizeOfLife.curvePoints.size() >= 2) {
			this->setParticleVarietyValue(particle->size, firePro._sizeOfLife, particle->timeToLive);
		}
		else {
			particle->size.pType = particlePropertyType::constValue;
			particle->size.constValue = this->getValueFromEmitterVarietyValue(firePro._startSize, firePro);
		}
	}

	//////---------------------旋转角度
	//if (firePro._parType == parType::render) {
		if (firePro._rotationOfLife.pType == emitterPropertyType::curve && firePro._rotationOfLife.curvePoints.size() >= 2) {
			this->setParticleVarietyValue(particle->rotation, firePro._rotationOfLife, particle->timeToLive);
		}
		else {
			particle->rotation.pType = particlePropertyType::constValue;
			particle->rotation.constValue = this->getValueFromEmitterVarietyValue(firePro._startRotation, firePro);
		}
	//}

	//////---------------------旋转角度速度
	//if (firePro._parType == parType::render) {
		if (firePro._rotationSpeedOfLife.pType == emitterPropertyType::curve && firePro._rotationSpeedOfLife.curvePoints.size() >= 2) {
			this->setParticleVarietyValue(particle->rotationSpeed, firePro._rotationSpeedOfLife, particle->timeToLive);
		}
		else {
			particle->rotationSpeed.pType = particlePropertyType::constValue;
			particle->rotationSpeed.constValue = this->getValueFromEmitterVarietyValue(firePro._startRotationSpeed, firePro);
		}
	//}

	//////---------------------倾斜角X
	if (firePro._parType == parType::render) {
		if (firePro._skewXOfLife.pType == emitterPropertyType::curve && firePro._skewXOfLife.curvePoints.size() >= 2) {
			this->setParticleVarietyValue(particle->skewX, firePro._skewXOfLife, particle->timeToLive);
		}
		else {
			particle->skewX.pType = particlePropertyType::constValue;
			particle->skewX.constValue = this->getValueFromEmitterVarietyValue(firePro._startSkewX, firePro);
		}
	}
	//发射出来时的 值

	// 设置粒子生命周期内的 值


	//////---------------------倾斜角X 速度
	if (firePro._parType == parType::render) {
		if (firePro._skewXSpeedOfLife.pType == emitterPropertyType::curve && firePro._skewXSpeedOfLife.curvePoints.size() >= 2) {
			this->setParticleVarietyValue(particle->skewXSpeed, firePro._skewXSpeedOfLife, particle->timeToLive);
		}
		else {
			particle->skewXSpeed.pType = particlePropertyType::constValue;
			particle->skewXSpeed.constValue = this->getValueFromEmitterVarietyValue(firePro._startSkewXSpeed, firePro);
		}
	}

	//////---------------------倾斜角Y
	if (firePro._parType == parType::render) {
		if (firePro._skewYOfLife.pType == emitterPropertyType::curve && firePro._skewYOfLife.curvePoints.size() >= 2) {
			this->setParticleVarietyValue(particle->skewY, firePro._skewYOfLife, particle->timeToLive);
		}
		else {
			particle->skewY.pType = particlePropertyType::constValue;
			particle->skewY.constValue = this->getValueFromEmitterVarietyValue(firePro._startSkewY, firePro);
		}
	}

	//////---------------------倾斜角Y 速度
	if (firePro._parType == parType::render) {
		if (firePro._skewYSpeedOfLife.pType == emitterPropertyType::curve && firePro._skewYSpeedOfLife.curvePoints.size() >= 2) {
			this->setParticleVarietyValue(particle->skewYSpeed, firePro._skewYSpeedOfLife, particle->timeToLive);
		}
		else {
			particle->skewYSpeed.pType = particlePropertyType::constValue;
			particle->skewYSpeed.constValue = this->getValueFromEmitterVarietyValue(firePro._startSkewYSpeed, firePro);
		}
	}


	//////---------------------不透明度
	if (firePro._parType == parType::render) {
		if (firePro._alphaOfLife.pType == emitterPropertyType::curve && firePro._alphaOfLife.curvePoints.size() >= 2) {
			this->setParticleVarietyValue(particle->alpha, firePro._alphaOfLife, particle->timeToLive);
		}
		else {
			particle->alpha.pType = particlePropertyType::constValue;
			particle->alpha.constValue = this->getValueFromEmitterVarietyValue(firePro._startAlpha, firePro);
		}
	}


	//////---------------------颜色
	if (firePro._parType == parType::render) {
		if (firePro._colorOfLife.pType == emitterPropertyType::curve && firePro._colorOfLife.curveColors.size() >= 2) {
			this->setParticleVarietyColorValue(particle->color, firePro._colorOfLife, particle->timeToLive);
		}
		else {
			particle->color.pType = particlePropertyType::constValue;
			particle->color.constColor = this->getValueFromEmitterVarietyColorValue(firePro._startColor, firePro);
		}
	}
}

// 更新一个 发射属性
void UpdateHelper::updateFirePro(ParticleEmitter* father , emitterFirePro& firePro , childrenPar& cPar, float dt) {

	if (!firePro._isActive) {
		return;
	}

	// 拖尾
	if (firePro._tailPro.isActive) {
		if (!firePro._tailPro.tailNode) {
			firePro._tailPro.tailNode = MotionStreak::create(firePro._tailPro.fade, firePro._tailPro.minSeg, firePro._tailPro.stroke, firePro._tailPro.color, "tail/" + firePro._tailPro.tailName);
			father->runningLayer->addChild(firePro._tailPro.tailNode , father->getLocalZOrder()-1);
		}
		else {
			//firePro._tailPro.tailNode->setPosition(father->getPosition());
			Vec2 worldPos = father->convertToWorldSpace(Vec2::ZERO);
			Vec2 nodePos = father->runningLayer->convertToNodeSpace(worldPos);
			firePro._tailPro.tailNode->setPosition(nodePos);
		}
	}
	else {
		if (firePro._tailPro.tailNode) {
			if (firePro._tailPro.tailNode->getParent()) {
				firePro._tailPro.tailNode->removeFromParent();
				firePro._tailPro.tailNode = nullptr;
			}
		}
	}

	//// --- 绘制调试框
	if (!firePro._debugDrawNode_centerPoint) {
		firePro._debugDrawNode_centerPoint = DrawNode::create();
		father->runningLayer->addChild(firePro._debugDrawNode_centerPoint, 600);
	}
	if (!firePro._debugDrawNode_fireAreaMode) {
		firePro._debugDrawNode_fireAreaMode = DrawNode::create();
		father->runningLayer->addChild(firePro._debugDrawNode_fireAreaMode, 600);
	}

	if (ParticleEmitter::isUseDrawNode == false) {
		firePro._debugDrawNode_centerPoint->clear();
		firePro._debugDrawNode_fireAreaMode->clear();
		//这句话只是让 nowFireAreaData 这个值变得不同
		firePro.nowFireAreaData.inRect.width = -1;
	}
	else {
		Vec2 fatherPos = father->convertToWorldSpace(Vec2::ZERO);
		fatherPos = father->runningLayer->convertToNodeSpace(fatherPos);

		firePro._debugDrawNode_centerPoint->setPosition(fatherPos);
		firePro._debugDrawNode_centerPoint->setRotation(father->getRotation());
		firePro._debugDrawNode_fireAreaMode->setPosition(fatherPos);
		firePro._debugDrawNode_fireAreaMode->setRotation(father->getRotation());

		firePro._debugDrawNode_centerPoint->clear();
		firePro._debugDrawNode_centerPoint->drawDot(Vec2(0, 0), 3, Color4F(1, 0, 1, 1));
		// 绘制发射区域
		if (firePro.nowFireAreaData != firePro._fireArea) {
			firePro.nowFireAreaData = firePro._fireArea;

			firePro._debugDrawNode_fireAreaMode->clear();
			if (firePro.nowFireAreaData.fAreaType == fireAreaType::rect) {
				firePro._debugDrawNode_fireAreaMode->drawRect(Vec2(-firePro.nowFireAreaData.outRect.width / 2, -firePro.nowFireAreaData.outRect.height / 2), Vec2(firePro.nowFireAreaData.outRect.width / 2, firePro.nowFireAreaData.outRect.height / 2), Color4F(1, 0, 0, 1));
				firePro._debugDrawNode_fireAreaMode->drawRect(Vec2(-firePro.nowFireAreaData.inRect.width / 2, -firePro.nowFireAreaData.inRect.height / 2), Vec2(firePro.nowFireAreaData.inRect.width / 2, firePro.nowFireAreaData.inRect.height / 2), Color4F(1, 1, 0, 1));
			}
			else if (firePro.nowFireAreaData.fAreaType == fireAreaType::circle) {
				firePro._debugDrawNode_fireAreaMode->drawCircle(Vec2(0, 0), firePro.nowFireAreaData.outCircleRadius, 0, 100, false, Color4F(1, 0, 0, 1));
				firePro._debugDrawNode_fireAreaMode->drawCircle(Vec2(0, 0), firePro.nowFireAreaData.inCircleRadius, 0, 100, false, Color4F(1, 1, 0, 1));
			}
			else if (firePro.nowFireAreaData.fAreaType == fireAreaType::polygon) {
				Vec2* pointVec = new Vec2[100];

				int index = 0;
				for (int i = 0; i < firePro.nowFireAreaData.polygonPoints.size(); ++i) {
					pointVec[index] = firePro.nowFireAreaData.polygonPoints[i];
					index++;
				}
				if (index > 0) {
					firePro._debugDrawNode_fireAreaMode->drawPolygon(pointVec, index, Color4F(0, 1, 1, 0), 1, Color4F(1, 0, 0, 1));

					for (int i = 0; i < firePro._fireArea.polygonTriangleVec.size(); ++i) {
						triangle triangleData = firePro._fireArea.polygonTriangleVec[i];
						Vec2 point1 = triangleData.point1;
						Vec2 point2 = triangleData.point2;
						Vec2 point3 = triangleData.point3;

						Vec2* pointVec = new Vec2[3];
						pointVec[0] = point1;
						pointVec[1] = point2;
						pointVec[2] = point3;
						firePro._debugDrawNode_fireAreaMode->drawPolygon(pointVec, 3, Color4F(CCRANDOM_0_1(), CCRANDOM_0_1(), CCRANDOM_0_1(), 0.6), 1, Color4F(0, 0, 0, 0));
					}

				}
			}
			else if (firePro.nowFireAreaData.fAreaType == fireAreaType::lines) {

				for (int i = 0; i < firePro.nowFireAreaData.linePoints.size() - 1; ++i) {
					Vec2 pointA;
					Vec2 pointB;

					pointA = firePro.nowFireAreaData.linePoints[i];
					pointB = firePro.nowFireAreaData.linePoints[i + 1];

					firePro._debugDrawNode_fireAreaMode->drawSegment(pointA, pointB, 1, Color4F(1, 0, 0, 1));

				}

			}
		}
	}


	// 设置 自定义 多边形发射区域 转成三角集合
	if (!firePro._fireArea.isChangePolygonToTriangleVec) {
		firePro._fireArea.polygonTriangleVec.clear();
		changePolygonToTriangleVec(firePro._fireArea.polygonPoints, &firePro._fireArea.polygonTriangleVec);
		firePro._fireArea.isChangePolygonToTriangleVec = true;

		firePro._fireArea.setPolygonAndLineAreaLineDis();

	}

	// 设置纹理
	if (firePro.nowTexName != firePro._texName) {
		firePro.nowTexName = firePro._texName;
		cPar.setTexture(CCTextureCache::sharedTextureCache()->addImage(firePro.nowTexName));
		//this->setTexture(CCTextureCache::sharedTextureCache()->addImage(firePro.nowTexName));
	}
	// 设置粒子最大数量
	if (firePro.nowMaxParticleNum != firePro._maxParticleNum) {
		firePro.nowMaxParticleNum = firePro._maxParticleNum;
		cPar.setTotalParticles(firePro.nowMaxParticleNum , father, firePro._emitterFileName);
		//this->setTotalParticles(firePro.nowMaxParticleNum);
	}

	// 设置运动模式
	if (firePro.nowPositionType != firePro._positionType) {
		cPar.setPositionType(firePro._positionType);
		//_renderer->setPositionType(firePro._positionType);
		firePro.nowPositionType = firePro._positionType;

		//this->resetSystem();
	}
	// 设置混合模式
	BlendFunc cbl = { (GLenum)firePro._sourceBlend, (GLenum)firePro._destBlend };
	cPar.setBlendFunc(cbl);

	float rate = 1.0 / firePro._emissionRate;

	float particleCount = cPar.getParticleCount();
	float totalParticles = cPar.getTotalParticles();

	// 创建新的粒子 , + _delayTime 表示延迟发射
	if (firePro._isDoPreFire && firePro._isDoDelayTime) {
		// 将粒子数量限制在设置的最大的粒子数量内
		if (particleCount < totalParticles)
		{
			firePro._emitCounter += dt;
		}

		int createNum = 0;
		float createTime = 0;
		while (particleCount < totalParticles && firePro._emitCounter > rate) {
			particleProperty* newPar = cPar.addParticle(father, firePro._emitterFileName , firePro._localZorder);
			
			this->initParticlePro(father, firePro, newPar);
			// 预先设置粒子经过的时间
			firePro._elapsed += rate;
			cPar.updateOneParticle(*newPar, dt - rate*createNum, true);
			
			createNum++;
			createTime += rate;
			particleCount++;
			firePro._emitCounter -= rate;
		}
		firePro._elapsed += dt - createTime;
	}


	// 是否预发射
	// 思路: 先将所有的粒子创建出来，然后对每个粒子的存活时间设置，再更新一次！
	if (!firePro._isDoPreFire) {
		do {
			firePro._isDoPreFire = true;
			if (firePro._preFireDuration <= 0) {
				break;
			}
			float rendererUpdateTime = 0;
			float rendererUpdateTimeValue = firePro._preFireDuration * firePro._duration;
			float needTime = totalParticles * rate;
			rendererUpdateTimeValue = (rendererUpdateTimeValue > needTime) ? needTime : rendererUpdateTimeValue;

			rendererUpdateTime = rendererUpdateTimeValue;

			if (rendererUpdateTime > 0) {
				float detal = 0;
				float interval = 0.015;
				while (rendererUpdateTime > 0) {
					// 已经经过的时间增加,以便表现发射器周期的曲线属性
					float preCreateTime = 0;
					int createNum = 0;
					detal += interval;
					while (detal > rate && particleCount < totalParticles) {
						//particleProperty* newPar = this->addParticle();
						particleProperty* newPar = cPar.addParticle(father, firePro._emitterFileName , firePro._localZorder);
						this->initParticlePro(father, firePro, newPar);
						// 预先设置粒子经过的时间
						detal -= rate;
						//_renderer->updateOneParticle(newPar, rendererUpdateTime - rate*createNum, false);
						cPar.updateOneParticle(*newPar, rendererUpdateTime - rate*createNum, false);
						////
						// 预发射完之后再设为0
						firePro._elapsed += rate;
						createNum++;
						preCreateTime += rate;
						particleCount++;
					}
					firePro._elapsed += interval - preCreateTime;
					if (firePro._elapsed > firePro._duration) {
						firePro._elapsed -= firePro._duration;
					}

					rendererUpdateTime -= interval;
				}
				//_renderer->updateParticle(rendererUpdateTimeValue, false);
			}
			firePro._elapsed = 0;
		} while (false);
	}

	//_elapsed += dt;
	// 是否停止系统
	// 如果还没有做延迟发射
	if (firePro._isDoPreFire && !firePro._isDoDelayTime) {
		firePro._elapsed += dt;
		if (firePro._elapsed > firePro._delayTime) {
			firePro._elapsed = 0;
			firePro._emitCounter = 0;
			firePro._isDoDelayTime = true;
		}
	}
	if (firePro._isDoDelayTime) {
		if (!firePro._isLoop && firePro._elapsed > firePro._duration)
		{
			//this->stopSystem();
			firePro._isActive = false;
		}
		if (firePro._isLoop && firePro._elapsed > firePro._duration) {
			firePro._elapsed -= firePro._duration;
		}
	}

}

