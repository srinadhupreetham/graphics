#include "main.h"
#include "timer.h"
#include "ball.h"
#include "water.h"
#include "boat.h"
#include "cannon.h"
#include "wave.h"
#include "flag.h"
#include "rock.h"
#include <cstdlib>
#include "barrel.h"
#include "wind_pointer.h"
#include "monster.h"
#include "boss.h"
#include "gift.h"
#include "island.h"
#include "square.h"
using namespace std;

GLMatrices Matrices;
GLuint     programID;
GLFWwindow *window;

/**************************
* Customizable functions *
**************************/

Ball ball1;
Water water1;
Boat boat1;
Ball bonus_ball[20],booster[20];
Barrel barrel[20];
Cannon cannon1;
Wave wave1,wave2;
Wind_pointer point;
Monster monster[20];
Flag flag;
Island island;
Gift gift[20];
Gift huge_gift;
Square square[2500];
float orient;
Boss boss;
int windcount=0;
int d=0,t=0;
float angle[20];
int changecount=0;
float eye_x,eye_y,eye_z,target_x,target_y,target_z;
float pan = 0.0f;
float e;
int count =0;
int jumpcount = 0;
double speed =0.4;
float x_rand,y_rand,x_rand2,y_rand2,x_rand3,y_rand3;
bool shoot =false,boost = false;
float screen_zoom = 1, screen_center_x = 0, screen_center_y = 0;
float camera_rotation_angle = 0;
int space1;
int air;
int j;
double xin,yin,xout,yout;
int mouse_count = 1;
int cam=0;
float wind_dir=0.0f,distance=0.1;
//float distance = 0.3;
int boostcount=0;
Rock rock[50];
Timer t60(1.0 / 60);
float RandomFloat(float a, float b) {
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}
/* Render the scene with openGL */
/* Edit this function according to your assignment */
void draw() {
    // clear the color and depth in the frame buffer
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // use the loaded shader program
    // Don't change unless you know what you are doing
    glUseProgram (programID);
//    eye_x = 0;
//    eye_y = 0;
//    eye_z = 8;
//    target_x = 0;
//    target_y = 0;
//    target_z = 0;

    // Eye - Location of camera. Don't change unless you are sure!!
//    glm::vec3 eye ( 5*cos(camera_rotation_angle*M_PI/180.0f),0,5*sin(camera_rotation_angle*M_PI/180.0f) );
//    glm::vec3 eye(0/*boat1.position.x*/,0/*+boat1.position.y*/,10);
    // Target - Where is the camera looking at.  Don't change unless you are sure!!
//    glm::vec3 target (boat1.position.x+(pan/8), boat1.position.y, 0);
    // Up - Up vector defines tilt of camera.  Don't change unless you are sure!!
    if (cam==1){
            target_x=boat1.position.x;
                         target_y=boat1.position.y;
            target_z=boat1.position.z;
        eye_x = boat1.position.x -(6*sin(-boat1.rotation*M_PI/180.0));
        eye_y = boat1.position.y -(6*cos(-boat1.rotation*M_PI/180.0));
        eye_z = boat1.position.z+9;
    }
    else if(cam==2){
        target_x = boat1.position.x + 10000*(3*sin(-boat1.rotation*M_PI/180.0));
        target_y=boat1.position.y + 10000*(3*cos(-boat1.rotation*M_PI/180.0));
        target_z=boat1.position.z;
        eye_x = boat1.position.x+(1*sin(-boat1.rotation*M_PI/180.0));
        eye_y =boat1.position.y+(1*cos(-boat1.rotation*M_PI/180.0));
        eye_z = boat1.position.z+3;
    }
    else if(cam ==3){
        target_x=boat1.position.x;
        target_y=boat1.position.y;
        target_z=boat1.position.z;
        eye_x = boat1.position.x -0.001;
        eye_y = boat1.position.y;
        eye_z = 50;
    }
    else if(cam ==4){
        target_x = boat1.position.x + 10000*(3*sin(-boat1.rotation*M_PI/180.0));
        target_y=boat1.position.y + 10000*(3*cos(-boat1.rotation*M_PI/180.0));
        target_z=boat1.position.z;
        eye_x = boat1.position.x-(1*sin(-boat1.rotation*M_PI/180.0));
        eye_y =boat1.position.y-(1*cos(-boat1.rotation*M_PI/180.0));
        eye_z = boat1.position.z+2;
    }
    else if(cam==5){
        target_x=boat1.position.x;
        target_y=boat1.position.y;
        target_z=0;
        eye_x = boat1.position.x;
        eye_y = boat1.position.y;
        eye_z = 30;
    }
    glm::vec3 eye(eye_x,eye_y,eye_z);
    glm::vec3 target(target_x,target_y,target_z);
    glm::vec3 up(0,0,1);

    // Compute Camera matrix (view)
    Matrices.view = glm::lookAt( eye, target, up ); // Rotating Camera for 3D
    // Don't change unless you are sure!!
    // Matrices.view = glm::lookAt(glm::vec3(0, 0, 3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)); // Fixed camera for 2D (ortho) in XY plane

    // Compute ViewProject matrix as view/camera might not be changed for this frame (basic scenario)
    // Don't change unless you are sure!!
    glm::mat4 VP = Matrices.projection * Matrices.view;

    // Send our transformation to the currently bound shader, in the "MVP" uniform
    // For each model you render, since the MVP will be different (at least the M part)
    // Don't change unless you are sure!!
    glm::mat4 MVP;  // MVP = Projection * View * Model

    // Scene render
    if (shoot){
        ball1.draw(VP);
    }
//    ball1.draw(VP);
    water1.draw(VP);
    island.draw(VP);
     wave1.draw(VP);
     wave2.draw(VP);
    boat1.draw(VP);
    point.draw(VP);
    cannon1.position.z = boat1.position.z+2;

    flag.position.z = boat1.position.z+4;

    cannon1.draw(VP);

    flag.draw(VP);
    for (j=0;j<50;j++)
    {
        rock[j].draw(VP);
    }
    for (j=0;j<20;j++)
    {
        barrel[j].draw(VP);
        bonus_ball[j].draw(VP);
        booster[j].draw(VP);
        monster[j].draw(VP);
        gift[j].draw(VP);
    }
    boss.draw(VP);
//    for(j=0;j<1;j++){
//        if(j%2==0){
//            square[j].set_position(50,50,-1);
//            square[j].draw(VP);
//        }
//    }
//    square.draw(VP);
    for(j=0;j<2500;j++){
        square[j].draw(VP);
    }
}

void jump(){
    d = 1;
    e=boat1.position.z;
    boat1.speedz = 0.5;
}

void tick_input(GLFWwindow *window) {
    int left  = glfwGetKey(window, GLFW_KEY_LEFT);
    int right = glfwGetKey(window, GLFW_KEY_RIGHT);
    int A = glfwGetKey(window, GLFW_KEY_A);
    int D = glfwGetKey(window, GLFW_KEY_D);
    int up = glfwGetKey(window, GLFW_KEY_UP);
    int down = glfwGetKey(window, GLFW_KEY_DOWN);
//    int space = glfwGetKey(window, GLFW_KEY_SPACE);
//    space1 = space;
    int F = glfwGetKey(window, GLFW_KEY_1);
    int B = glfwGetKey(window, GLFW_KEY_2);
    int H = glfwGetKey(window, GLFW_KEY_3);
    int S = glfwGetKey(window, GLFW_KEY_4);
    int T = glfwGetKey(window, GLFW_KEY_5);
    int L = glfwGetKey(window, GLFW_KEY_0);
    if(mouse_count == 1)
       {
           glfwGetCursorPos(window,&xin,&yin);
       }
    int mouseleft = glfwGetMouseButton(window,GLFW_MOUSE_BUTTON_LEFT);
    mouse_count=0;
        if(mouse_count == 0)
        {
           glfwGetCursorPos(window,&xout,&yout);
    //       std :: cout << xin;
    //       std :: cout << "\n";
        }
    if (L) {
        shoot=true;
        ball1.position.x = cannon1.position.x;
        ball1.position.y = cannon1.position.y;
        ball1.position.z = cannon1.position.z;
        ball1.angle = cannon1.rotation;
    }
    if (left) {
//        boat1.position.x -= 0.1;
        boat1.rotation += 1;
        flag.rotation += 1;
        cannon1.rotation = boat1.rotation;
        cannon1.X = boat1.position.x;
        cannon1.Y = boat1.position.y;
        if (boat1.rotation > 360)
        {
            boat1.rotation = 0;
        }
    }
    if (H){
        cam =3;
        target_x=0;
        target_y=0;
        target_z=1;
        eye_x = 0;
        eye_y = 0;
        eye_z = 40;
    }
    if (T){
        cam =5;
        target_x=0;
        target_y=0;
        target_z=1;
        eye_x = 0;
        eye_y = 0;
        eye_z = 40;
    }
    if (F){
        cam =1;
        target_x=boat1.position.x;
        target_y=boat1.position.y;
        target_z=boat1.position.z;
        eye_x = boat1.position.x -(3*sin(-boat1.rotation*M_PI/180.0));
        eye_y = boat1.position.y -(3*cos(-boat1.rotation*M_PI/180.0));
        eye_z = 4;
    }
    if (B){
        cam =2;
        target_x = boat1.position.x + 10000*(3*sin(-boat1.rotation*M_PI/180.0));
        target_y=boat1.position.y + 10000*(3*cos(-boat1.rotation*M_PI/180.0));
        target_z=boat1.position.z;
        eye_x = boat1.position.x;
        eye_y =boat1.position.y;
        eye_z = boat1.position.z+3;
    }
    if (A || ((mouseleft == GLFW_PRESS) && (xout - xin <0))){
        cannon1.rotation += 1;
    }
    if (D || ((mouseleft == GLFW_PRESS) && (xout - xin >0)) ){
        cannon1.rotation -= 1;
    }
    if (S){
        cam =4;
    }
    if (right) {
//        boat1.position.x += 0.1;
        boat1.rotation -= 1;
        flag.rotation -= 1;
        cannon1.rotation = boat1.rotation;
        cannon1.X = boat1.position.x;
        cannon1.Y = boat1.position.y;
        if (boat1.rotation > 360)
        {
            boat1.rotation = 0;
        }
    }
    if (up) {
//        float distance = 0.1;
//        if(boostcount > 80 && boostcount <120)
//        {
//           distance = 0.4;
//        }
//        else if (boostcount > 120)
//        {
//            distance = 0.4;
//            boostcount = 0;
//        }
//        else
//            distance = 0.4;

        boat1.position.y += boat1.velocity*cos(boat1.rotation * M_PI/180.0f);
        flag.position.y = boat1.position.y;
        cannon1.position.y = boat1.position.y;

        boat1.position.x -= boat1.velocity*sin(boat1.rotation * M_PI/180.0f);
        flag.position.x = boat1.position.x;
        cannon1.position.x = boat1.position.x;

    }
    if (down) {
//        float distance = 0.1;
//        if(boostcount > 80 && boostcount <120)
//        {
//           distance = 0.4;
//        }
//        else if (boostcount > 120)
//        {
//            distance = 0.4;
//            boostcount = 0;
//        }
//        else
//            distance = 0.4;

        boat1.position.y -= boat1.velocity*cos(boat1.rotation * M_PI/180.0f);
        flag.position.y = boat1.position.y;
        cannon1.position.y = boat1.position.y;

        boat1.position.x += boat1.velocity*sin(boat1.rotation * M_PI/180.0f);
        flag.position.x = boat1.position.x;
        cannon1.position.x = boat1.position.x;

    }
}

void tick_elements() {
    orient = atan2(boss.position.y - boat1.position.y, boss.position.x - boat1.position.x);
    boss.position.x -= 0.1*(cos(orient));
    boss.position.y -= 0.1*(sin(orient));
//    boat1.position.x -= 0.005*(sin(wind_dir*M_PI/180.0));
//    boat1.position.y += 0.005*(cos(wind_dir*M_PI/180.0));
    flag.position.x = boat1.position.x;
    flag.position.y = boat1.position.y;
    cannon1.position.x = boat1.position.x;
    cannon1.position.y = boat1.position.y;
//    if((int(boat1.rotation)%180 - int(wind_dir)%180 ) !=90)
//     {
// //       if(boat1.rotation < int(wind_dir)){
//          boat1.rotation += 0.1;
// //    }
// //    else
// //        boat1.rotation -= 0.1;
//    }
 //    cannon1.rotation = boat1.rotation;
     flag.rotation = boat1.rotation;
     point.rotation = -wind_dir;
    point.position.x = boat1.position.x + 8*sin(boat1.rotation*M_PI/180.0);
    point.position.y = boat1.position.y - 8*cos(boat1.rotation*M_PI/180.0);
    if((int(wind_dir)%360)-(int(boat1.rotation)%360) < 180){
        flag.flag = 1;
    }
    else
        flag.flag = -1;
//    flag.position.z = boat1.position.z+4;
    for(j=0;j<50;j++){
        if(detect_collision_rock(boat1.bounding_box(),rock[j].bounding_box()))
        {
//            printf("working HUrrah");
//            boat1.position.z+=
//            2;
            t = 1;
            if(boat1.position.x < rock[j].position.x)
            {
                boat1.position.x -= 2;
            }
            else
                boat1.position.x += 2;
            if(boat1.position.y < rock[j].position.x)
            {
                boat1.position.y -= 2;
            }
            else
                boat1.position.y += 2;
            boat1.position.z = 2;
            boat1.health -= 10;

        }
    }
    for(j=0;j<20;j++){
        if(detect_collision_bonus(boat1.bounding_box(),barrel[j].bounding_box()))
        {
//            if(boat1.position.x < barrel[j].position.x)
//            {
//                boat1.position.x -= 1;
//            }
//            else
//                boat1.position.x += 1;
//            if(boat1.position.y < barrel[j].position.x)
//            {
//                boat1.position.y -= 1;
//            }
//            else
//                boat1.position.y += 1;
//            boat1.position.z = 1;
            boat1.health += 10;
            barrel[j].position.x = RandomFloat(0,300);
            bonus_ball[j].position.x = barrel[j].position.x;
        }
    }
//    for(j=0;j<20;j++){
//        if(monster[j].position.x )
//    }
    if(count > 40)
    {
        boat1.tickup();
        wave1.tickup();
        wave2.tickup();
        for(j=0;j<20;j++)
        {
            bonus_ball[j].tickup();
            barrel[j].tickup();
        }
    }
    else{
         boat1.tickdown();
        wave1.tickdown();
        wave2.tickdown();
        for(j=0;j<20;j++)
        {
            bonus_ball[j].tickdown();
            barrel[j].tickdown();
        }
    }
    if(d==1){
        boat1.speedz -= 0.02;
        boat1.position.z += boat1.speedz;
        if(boat1.position.z < e){
            boat1.speedz = 0.0;
            d =0;
            boat1.position.z = 2.0;
        }
    }
    if(shoot) {
        ball1.position.x -= 0.5*sin(ball1.angle*M_PI/180.0f);
        ball1.position.y += 0.5*cos(ball1.angle*M_PI/180.0f);
    }
    count += 1;
    if(count > 80)
    {
        count = 0;
    }
    for(j=0;j<20;j++){
        if(((booster[j].position.x) < (boat1.position.x + 2)) && ((booster[j].position.x) > (boat1.position.x - 2)) && ((booster[j].position.y) < (boat1.position.y + 4)) && ((booster[j].position.y) > (boat1.position.y - 4))){
//            printf("DONEndnflksndlv");
//            boat1.position.z += 2;
            booster[j].position.x = RandomFloat(-200,200);
            booster[j].position.y = RandomFloat(-200,200);
            boat1.velocity = 0.6;
            boost = true;
        }
        if(boostcount > 100){
            boostcount=0;
            boat1.velocity = 0.3;
            boost = false;
        }
        if(((gift[j].position.x) < (boat1.position.x + 2)) && ((gift[j].position.x) > (boat1.position.x - 2)) && ((gift[j].position.y) < (boat1.position.y + 4)) && ((gift[j].position.y) > (boat1.position.y - 4))){
//            printf("DONEndnflksndlv");
            gift[j].position.x = RandomFloat(-200,200);
            gift[j].position.y = RandomFloat(-200,200);
            boat1.score += 10;
        }
    }
    if(boost){
        boostcount+=1;
    }
    wave1.tick();
    wave2.tick();
    camera_rotation_angle += 1;
    for(j=0;j<20;j++){
        bonus_ball[j].rotation += 10;
        booster[j].rotation+=10;
        if(bonus_ball[j].rotation > 100){
            bonus_ball[j].rotation = 0;
        }
        gift[j].tick();
    }
    if(windcount %30000 == 0)
    {

        wind_dir = RandomFloat(0,360);
//         boat1.rotation += wind_dir;

        printf("%f\n",wind_dir);
    }
    if(boat1.rotation > 360){
        boat1.rotation = 0;
    }
    if(flag.rotation > 360){
        flag.rotation =0;
    }
    if(cannon1.rotation > 360){
        cannon1.rotation =0;
    }
//    if(windcount > 100)
//    {
//        windcount = 0;
//    }
    windcount+=1;
    if(changecount >120)
    {
        changecount =0;
        for(j=0;j<20;j++){
            angle[j]=RandomFloat(0,360);
        }
    }
    for(j=0;j<20;j++)
    {
        monster[j].position.x += /*RandomFloat(0.3,1.0)*/0.3*cos(angle[j]*M_PI/180.0);
        monster[j].position.y += /*RandomFloat(0.4,1.0*/0.3*sin(angle[j]*M_PI/180.0);
        if (monster[j].position.x > 100 ||monster[j].position.x < -100){
            monster[j].position.x = 80;
        }
        if (monster[j].position.y > 200 ||monster[j].position.y < -200){
            monster[j].position.y = 180;
        }

    }
    changecount += 1;
}

/* Initialize the OpenGL rendering properties */
/* Add all the models to be created here */
void initGL(GLFWwindow *window, int width, int height) {
    /* Objects should be created before any other gl function and shaders */
    // Create the models


    water1      = Water(0,0,-2,500,500,1,COLOR_BLUE);
    island      = Island(0,1000,2,1000,500,5,COLOR_BROWN);
    huge_gift   = Gift(0,1020,8,COLOR_GREEN);
    boat1       = Boat(0,0,2,8,2,1,COLOR_GREEN);
    cannon1     = Cannon(boat1.position.x,boat1.position.y,boat1.position.z+2,0.2,2,3);
    ball1       = Ball(cannon1.position.x, cannon1.position.y, cannon1.position.z, COLOR_RED);

    wave1       = Wave(boat1.position.x - 8,boat1.position.y-3,boat1.position.z-2,1.5,10,3);
    wave2       = Wave(boat1.position.x + 8,boat1.position.y-3,boat1.position.z-2,1.5,10,3);
    point       =Wind_pointer(boat1.position.x,boat1.position.y,boat1.position.z+1,COLOR_WAVE);
    flag = Flag(boat1.position.x,boat1.position.y,boat1.position.z+4,3,1,1,1,0.0f);
    target_x=boat1.position.x;
    target_y=boat1.position.y;
    target_z=boat1.position.z;
    eye_x = boat1.position.x -(3*sin(-boat1.rotation*M_PI/180.0));
    eye_y = boat1.position.y -(3*cos(-boat1.rotation*M_PI/180.0));
    boat1.health = 100;
    eye_z = 4;
    boss        = Boss(1000,1000,0,COLOR_BASETOP);
    for (j=0;j<50;j++)
    {
        if (j%2 == 0){
            x_rand = RandomFloat(4,200) ;
            y_rand = RandomFloat(4,200) ;
        }
        if (j%2 == 1){
            x_rand = -RandomFloat(4,200) ;
            y_rand = -RandomFloat(4,200) ;
        }
        rock[j] = Rock(x_rand,y_rand,4,COLOR_BROWN);
    }
    for(j=0;j<20;j++)
    {
        if (j%2 == 0){
            x_rand = RandomFloat(4,200) ;
            y_rand = RandomFloat(4,200) ;
            x_rand3 = RandomFloat(4,200) ;
            y_rand3 = RandomFloat(4,200) ;
        }
        if (j%2 == 1){
            x_rand = -RandomFloat(4,200) ;
            y_rand = -RandomFloat(4,200) ;
            x_rand3 = -RandomFloat(4,200) ;
            y_rand3 = -RandomFloat(4,200) ;

        }
        x_rand2 = RandomFloat(5,10);
        y_rand2 = RandomFloat(5,10);
        booster[j] = Ball(x_rand+x_rand2,y_rand+y_rand2,1.5,COLOR_GREEN);
        barrel[j] = Barrel(x_rand,y_rand,0,0.75,6,2);
        bonus_ball[j] =Ball(x_rand,y_rand,6.5,COLOR_RED);
        monster[j] =Monster(x_rand3,y_rand3,2,COLOR_DOM);
        gift[j] = Gift(x_rand2+x_rand3,y_rand2+y_rand3,3,COLOR_BLACK);
    }
    for(j=0;j<2500;j++){
//        if((j/50)%2==0)
//        square[j] = Square((j%50)*10 - 250,(j/50)*10 -250,-1,5,COLOR_BLACK);
//        else
            square[j] = Square((j%50)*10 - 250+5,(j/50)*10 -250,0.55,10,COLOR_BLACK);
//        square[j] = Square(3,4,-1,2,COLOR_BLACK);
    }
//    square = Square(5,5,0.55,5,COLOR_BLACK);
    // Create and compile our GLSL program from the shaders
    programID = LoadShaders("Sample_GL.vert", "Sample_GL.frag");
    // Get a handle for our "MVP" uniform
    Matrices.MatrixID = glGetUniformLocation(programID, "MVP");


    reshapeWindow (window, width, height);

    // Background color of the scene
    glClearColor (COLOR_BACKGROUND.r / 256.0, COLOR_BACKGROUND.g / 256.0, COLOR_BACKGROUND.b / 256.0, 0.25f); // R, G, B, A
    glClearDepth (1.0f);

    glEnable (GL_DEPTH_TEST);
    glDepthFunc (GL_LEQUAL);

    cout << "VENDOR: " << glGetString(GL_VENDOR) << endl;
    cout << "RENDERER: " << glGetString(GL_RENDERER) << endl;
    cout << "VERSION: " << glGetString(GL_VERSION) << endl;
    cout << "GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
}


int main(int argc, char **argv) {
    srand(time(0));
    int width  = 600;
    int height = 600;

    window = initGLFW(width, height);

    initGL (window, width, height);

    /* Draw in loop */
    while (!glfwWindowShouldClose(window)) {
        // Process timers

        if (t60.processTick()) {
            // 60 fps
            // OpenGL Draw commands
            draw();
            // Swap Frame Buffer in double buffering
            glfwSwapBuffers(window);

            tick_elements();
            tick_input(window);
            if(boat1.health < 0){
                break;
            }
        }

        // Poll for Keyboard and mouse events
        glfwPollEvents();
    }

    quit(window);
}

bool detect_collision_rock(bounding_box_t a, bounding_box_t b) {
    return (abs(a.x - b.x) * 2 < (a.width + b.width)) &&
           (abs(a.y - b.y) * 2 < (a.length + b.length)) && (abs(a.z - b.z)*2 <= (a.height+b.height));
}
bool detect_collision_bonus(bounding_box_t a, bounding_box_t b) {
    return (abs(a.x - b.x) * 2 < (a.width + b.width)) &&
           (abs(a.y - b.y) * 2 < (a.length + b.length)) && (abs(a.z - b.z)*2 <= (a.height+b.height));
}

void reset_screen() {
    float fov1 = 90.0f;
    float top    = screen_center_y + 4 / screen_zoom;
    float bottom = screen_center_y - 4 / screen_zoom;
    float left   = screen_center_x - 4 / screen_zoom;
    float right  = screen_center_x + 4 / screen_zoom;
//    float aspect = 6.0
    Matrices.projection = glm::infinitePerspective(fov1, 0.5f, 0.2f);
}
