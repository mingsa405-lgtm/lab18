#include <algorithm>
using namespace std;

struct Rect{
    double x, y, w, h;
};

double overlap(Rect *r1, Rect *r2){

    // ขอบของ r1
    double l1 = r1->x;
    double r1r = r1->x + r1->w;
    double t1 = r1->y;
    double b1 = r1->y - r1->h;   // h ลง

    // ขอบของ r2
    double l2 = r2->x;
    double r2r = r2->x + r2->w;
    double t2 = r2->y;
    double b2 = r2->y - r2->h;

    // จัดบน–ล่างให้ถูก
    double top1 = max(t1, b1);
    double bot1 = min(t1, b1);
    double top2 = max(t2, b2);
    double bot2 = min(t2, b2);

    // 1) เช็ค: R2 โดนทับหมด
    if (l2 >= l1 && r2r <= r1r &&
        bot2 >= bot1 && top2 <= top1){
        return r2->w * r2->h;
    }

    // 2) พื้นที่ซ้อนจริง
    double width  = min(r1r, r2r) - max(l1, l2);
    double height = min(top1, top2) - max(bot1, bot2);

    if (width <= 0 || height <= 0)
        return 0.0;

    return width * height;
}
