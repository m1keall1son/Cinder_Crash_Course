#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class BouncingBallsApp : public App {
  public:
    BouncingBallsApp();
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    
    vec2 mPosition;
    vec2 mSpeed;
    float mRadius;
};

BouncingBallsApp::BouncingBallsApp(){
    
}

void BouncingBallsApp::setup()
{
    mPosition = getWindowCenter();
    mSpeed = randVec2();
    mRadius = 30;
}

void BouncingBallsApp::mouseDown( MouseEvent event )
{
}

void BouncingBallsApp::update()
{
    mPosition += mSpeed;
    if( mPosition.x > getWindowWidth() - mRadius || mPosition.x < mRadius ){
        mSpeed.x *= -1;
    }
    if( mPosition.y > getWindowHeight() - mRadius || mPosition.y < mRadius){
        mSpeed.y *= -1;
    }
}

void BouncingBallsApp::draw()
{
	gl::clear( Color( 0, 0, 0 ) );
    
    gl::drawSolidCircle( mPosition, mRadius );
    
 
}


CINDER_APP( BouncingBallsApp, RendererGl( RendererGl::Options().msaa(16) ) )











