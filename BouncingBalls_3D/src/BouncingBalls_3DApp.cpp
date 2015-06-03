#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "cinder/CameraUi.h"

#include "BouncingBall.h"
#include "cinder/Rand.h"

using namespace ci;
using namespace ci::app;
using namespace std;

const int NUM_BALLS = 50;

class BouncingBalls_3DApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    
    vector<BouncingBallRef> mBalls;
    AxisAlignedBox mBox;
    
    CameraPersp mCamera;
    CameraUi mUI;
    
};

void BouncingBalls_3DApp::setup()
{
    for( int i = 0; i < NUM_BALLS; i++ ){
        mBalls.push_back( BouncingBall::create( randVec3() * 3.f ) );
    }
    
    mBox = AxisAlignedBox( vec3(-25), vec3(25) );
    
    mCamera.setPerspective(60, getWindowAspectRatio(), .1, 10000);
    mCamera.lookAt(vec3(0,0,30), vec3(0));
    
    mUI.connect( getWindow() );
    mUI.setCamera( &mCamera );
    
    gl::enableDepthRead();
    gl::enableDepthWrite();
    
}

void BouncingBalls_3DApp::mouseDown( MouseEvent event )
{
}

void BouncingBalls_3DApp::update()
{
    for( auto & ball : mBalls ){
        ball->checkBounds(mBox);
        ball->update();
    }
}

void BouncingBalls_3DApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) );
    
    gl::ScopedMatrices pushMatrix;
    gl::setMatrices( mCamera );
    
    gl::drawStrokedCube(mBox);
    
    for( auto & ball : mBalls ){
        ball->draw();
    }
}

CINDER_APP( BouncingBalls_3DApp, RendererGl )












