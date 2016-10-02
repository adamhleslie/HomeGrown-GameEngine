#include "BoundMovement.h"

#include <cstdlib>
#include <OgreCamera.h>
#include <OgreEntity.h>
#include <OgreRoot.h>

#include "AudioPlayer.h"

using Ogre::Vector3;

void BoundMovement::update()
{
	Vector3 initial = mBallNode->getPosition();
	mCamera->lookAt(initial);

	Vector3 next = initial + mBallVelocity;

	if (mBallVelocity.x >= 0 && (next.x + mBallRadius > mWallDistances.x) ||
		mBallVelocity.x <= 0 && (next.x - mBallRadius < -mWallDistances.x))
	{
			mBallVelocity.x = -mBallVelocity.x;
			mAudioPlayer->playSound(1);
	}

	if (mBallVelocity.y >= 0 && (next.y + mBallRadius > mWallDistances.y) ||
		mBallVelocity.y <= 0 && (next.y - mBallRadius < -mWallDistances.y))
	{
			mBallVelocity.y = -mBallVelocity.y;
			mAudioPlayer->playSound(2);
	}

	if (mBallVelocity.z >= 0 && (next.z + mBallRadius > mWallDistances.z) ||
		mBallVelocity.z <= 0 && (next.z - mBallRadius < -mWallDistances.z))
	{
			mBallVelocity.z = -mBallVelocity.z;
			mAudioPlayer->playSound(3);
	}

	mBallNode->translate(mBallVelocity);
}

void BoundMovement::onLoadCallback (Entity* entity)
{
	mAudioPlayer = entity->getComponent<AudioPlayer>();
	assert(mAudioPlayer);

	mAudioPlayer->playSound(4);
}