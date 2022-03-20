#include<bangtal.h>

#include<time.h>



SceneID scene1;

ObjectID problem;



ObjectID block[9];



int X{ 9 } = { 440,640,840,440,640,840,440,640,840 };

int Y[9] = { 560,560,560,360,360,360,160,160,160 };

bool checked[9];



ObjectID createObject(const char* name, const char* image, SceneID scene, int x, int y, bool shown) {

    ObjectID object = createObject(image);

    locateObject(object, scene, x, y);

    if (shown) {

        showObject(object);

    }

    return object;

}



bool checkin(int x, int y, int cx, int cy, int r) {

    return(x<cx + r && x>cx - r && y<cy + r && y>cy - r)



}



void mouseCallback(ObjectID object, int x, int y, MouseAction action) {

    if (object == block[i] && action == MOUSE_DRAG_DOWN) {

        locateObject(block[i], scene1, x, y - 200);

    }

    else if (object == block[i] && action == MOUSE_DRAG_UP) {

        locateObject(block[i], scene1, x, y + 200);

    }

    else if (object == block[i] && action == MOUSE_DRAG_LEFT) {

        locateObject(block[i], scene1, x - 200, y);

    }

    else if (object == block[i] && action == MOUSE_DRAG_RIGHT) {

        locateObject(block[i], scene1, x + 200, y);

    }

    if (object == block[i]) {













        for (int i = 0; i < 9; i++) {



            if ((checked[i] == false) && checkin(x, y, X[i], Y[i], 200)) {

                checked[i] = true;

            }

        }



    else {

        bool completed = true;

        for (int i = 0; i < 9; i++) {

            if (checked[i] == false) {

                completed = false;

            }

        }

        if (completed) {

            endGame();

        }

    }

    }





}







int main() {



    setMouseCallback(mouseCallback);



    scene1 = createScene("slamdunk.png");



    createObject(block[8], "block[8].png", scene1, 440, 560, true);

    createObject(block[4], "block[4].png", scene1, 640, 560, true);

    createObject(block[5], "block[5].png", scene1, 840, 560, true);

    createObject(block[6], "block[6].png", scene1, 440, 360, true);

    createObject(block[0], "block[0].png", scene1, 640, 360, true);

    createObject(block[1], "block[1].png", scene1, 840, 360, true);

    createObject(block[2], "block[2].png", scene1, 440, 160, true);

    createObject(block[3], "block[3].png", scene1, 640, 160, true);

    createObject(block[7], "block[7].png", scene1, 840, 160, true);





    time_t start = time(NULL);



    int sum = 0;

    for (int i = 0; i < 100000; ++i)sum += i;

    printf("sum=%d\n", sum);



    time_t end = time(NULL);

    printf("Time:%1f\n", difftime(end, start));





    showMessage("퍼즐을 맞추세요!!");

    startGame(scene1);



}