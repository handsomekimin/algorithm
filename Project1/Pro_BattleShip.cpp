//bluesquanium 4340
//#include <stdio.h>

#define MISS 0
#define CARRIER 1
#define BATTLESHIP 2
#define CRUISER 3
#define SUBMARINE 4
#define DESTROYER 5

#define DIR 2
int dy[DIR] = { -1, 0 };
int dx[DIR] = { 0, 1 };

typedef struct {
    int y;
    int x;
    int type;
} Point;

int m[12][12];
int score[12][12];
int rCnt;
int ship[6];
int S[6];
Point st[100];
int stCnt;

extern int fire(int r, int c);

void init(int limit) {
    S[1] = 5, S[2] = 4, S[3] = 3, S[4] = 3, S[5] = 2;
    return;
}

void play() {
    for (int i = 0; i < 12; i++) {
        m[i][0] = -1;
        m[0][i] = -1;
        m[i][11] = -1;
        m[11][i] = -1;
    }
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            m[i][j] = 0;
            score[i][j] = 0;
        }
    }
    stCnt = 0;
    rCnt = 17;
    ship[1] = 5, ship[2] = 4, ship[3] = 3, ship[4] = 3, ship[5] = 2;

    while (rCnt) {
        // score 업데이트
        int highidx[2], highs = -1, window;
        for (int i = 1; i <= 5; i++) {
            if (ship[i] == S[i]) {
                window = S[i];
                break;
            }
        }
        for (int i = 1; i <= 10; i++) {
            for (int j = 1; j <= 10; j++) {
                if (m[i][j] == 0) {
                    int s = 0;
                    for (int d = 0; d < DIR; d++) {
                        int n_y = i + dy[d], n_x = j + dx[d], step = 1;
                        while (m[n_y][n_x] == 0 && (step < window)) {
                            s++;
                            step++;

                            n_y += dy[d];
                            n_x += dx[d];
                        }
                        n_y = i - dy[d];
                        n_x = j - dx[d];
                        step = 1;
                        while (m[n_y][n_x] == 0 && (step < window)) {
                            s++;
                            step++;

                            n_y -= dy[d];
                            n_x -= dx[d];
                        }
                    }
                    score[i][j] = s;
                    if (highs < s) {
                        highs = s;
                        highidx[0] = i;
                        highidx[1] = j;
                    }
                }
                else {
                    score[i][j] = -1;
                }
                // printf("%3d ", score[i][j]);
            }  // putchar('\n');
        }      // putchar('\n');

        int isHit;
        isHit = fire(highidx[0] - 1, highidx[1] - 1);
        if (isHit) {
            Point t = { highidx[0], highidx[1], isHit };
            st[stCnt++] = t;
            rCnt--;
            ship[isHit]--;
            m[highidx[0]][highidx[1]] = isHit;
        }
        else {
            m[highidx[0]][highidx[1]] = -1;
        }

        while (stCnt) {
            int willHit[2][2], probHit[4][2], pCnt = 0, wCnt = 0;
            Point cur = st[--stCnt];
            if (ship[cur.type]) {
                for (int d = 0; d < DIR; d++) {
                    int n_y = cur.y + dy[d], n_x = cur.x + dx[d], thisDir = 0;
                    while (m[n_y][n_x] == cur.type) {
                        n_y += dy[d];
                        n_x += dx[d];
                        thisDir = 1;
                    }
                    int n_y2 = n_y, n_x2 = n_x;
                    n_y = cur.y - dy[d];
                    n_x = cur.x - dx[d];
                    while (m[n_y][n_x] == cur.type) {
                        n_y -= dy[d];
                        n_x -= dx[d];
                        thisDir = 1;
                    }
                    if (m[n_y2][n_x2] == 0) {
                        if (thisDir) {
                            willHit[wCnt][0] = n_y2;
                            willHit[wCnt++][1] = n_x2;
                        }
                        else {
                            probHit[pCnt][0] = n_y2;
                            probHit[pCnt++][1] = n_x2;
                        }
                    }
                    if (m[n_y][n_x] == 0) {
                        if (thisDir) {
                            willHit[wCnt][0] = n_y;
                            willHit[wCnt++][1] = n_x;
                        }
                        else {
                            probHit[pCnt][0] = n_y;
                            probHit[pCnt++][1] = n_x;
                        }
                    }
                }

                int attack[2];
                if (wCnt) {
                    if (wCnt == 1) {
                        attack[0] = willHit[0][0];
                        attack[1] = willHit[0][1];
                    }
                    else {
                        if (score[willHit[0][0]][willHit[0][1]] > score[willHit[1][0]][willHit[1][1]]) {
                            attack[0] = willHit[0][0];
                            attack[1] = willHit[0][1];
                        }
                        else {
                            attack[0] = willHit[1][0];
                            attack[1] = willHit[1][1];
                        }
                    }
                }
                else {
                    if (pCnt == 1) {
                        attack[0] = probHit[0][0];
                        attack[1] = probHit[0][1];
                    }
                    else {
                        int maxi = score[probHit[0][0]][probHit[0][1]], idx = 0;
                        for (int i = 0; i < pCnt; i++) {
                            if (maxi < score[probHit[i][0]][probHit[i][1]]) {
                                idx = i;
                            }
                        }
                        attack[0] = probHit[idx][0];
                        attack[1] = probHit[idx][1];
                    }
                }

                int isHit = fire(attack[0] - 1, attack[1] - 1);
                if (!isHit) {
                    st[stCnt++] = cur;
                    m[attack[0]][attack[1]] = -1;
                }
                else if (isHit == cur.type) {
                    st[stCnt++] = cur;
                    rCnt--;
                    ship[cur.type]--;
                    m[attack[0]][attack[1]] = isHit;
                }
                else {  // 다른 배 히팅
                    Point t = { attack[0], attack[1], isHit };
                    rCnt--;
                    ship[isHit]--;
                    st[stCnt++] = cur;
                    st[stCnt++] = t;
                    m[attack[0]][attack[1]] = isHit;
                }
            }
        }
    }
    return;
}