http://remus.rutgers.edu/~rhoads/Code/code.html


int dayofweek( year, month, day )     	/* 0 = Sunday */
     int year, month, day;		/* y > 1752 */
   {
   static int offset[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
   year -= month < 3;
   return (year + year/4 - year/100 + year/400 + offset[month-1] + day) % 7;
   }


int dayofweek( int year, int month, int day)   /* 0=sunday, 1=monday, etc. */
   {
   int a = (14-month) / 12;
   int y = year - a;
   int m = month + 12*a - 2;

   return (day + y + y/4 - y/100 + y/400 + (31*m)/12) % 7;
   }

   
int isLeapYear(unsigned int year)
{
    assert(year > 1581);
    return(((year % 4 == 0) && (year % 100)) || (year % 400 == 0));
}



    public static void sort(Vector v) {
        int n = v.size();
        Obj[] v2 = new Obj[n];
        char us[] = new char[n];
        int j, t,i;
        Obj p1, p2;
        for(i=0;i<n;i++) {
            p1 = null;
            t = -1;
            for(j=0;j<n;j++) {
                if(us[j]==1) continue;
                p2 = (Obj) v.elementAt(j);
                if(p1==null || p1.compareTo(p2)>0) {
                    t = j;
                    p1 = p2;
                }
            }
            us[t] = 1;
            v2[i] = (p1);
        }
        v.removeAllElements();
        for(i=0;i!=n;i++) {
            v.addElement(v2[i]);
        }
    }

    
class Point {

    int x, y;

    void clear(int a, int b) {
        this.x = a;
        this.y = b;
    }

    Point() {
    }

    Point(int a, int b) {
        this.x = a;
        this.y = b;
    }
}

class Reta {

    Point p1 = new Point(), p2 = new Point();

    double a, b;

    double dist;

    void clear(int x1, int y1, int x2, int y2) {
        this.p1.x = x1;
        this.p1.y = y1;
        this.p2.x = x2;
        this.p2.y = y2;
        this.a = (y2 - y1) / (x2 - x1);
        this.b = y1 - this.a * x1;
        calc();
    }

    public void clear(Point p, Point e) {
        this.p1 = p;
        this.p2 = e;
        this.dist = Math.sqrt((this.p1.x - this.p2.x) * (this.p1.x - this.p2.x)
                + (this.p1.y - this.p2.y) * (this.p1.y - this.p2.y));
        calc();
    }

    private void calc() {
        this.a = (this.p2.y - p1.y) / (p2.x - p1.x);
        this.b = this.p1.y - this.a * this.p1.x;
    }

    public boolean cruza(Reta reta) {
        double x = (reta.b - this.b) / (reta.a - a);
        double y = a * x + this.b;
        return contem(x, y);
    }


    public boolean contem(double x, double y) {
        if ((x >= this.p1.x && x <= this.p2.x)
                || (x <= this.p1.x && x >= this.p2.x)) {
            if ((y >= this.p1.y && y <= this.p2.y)
                    || (y <= this.p1.y && y >= this.p2.y)) {
                return true;
            }
        }
        return false;
    }

    public double distTo(Reta r) {
        return 0;
    }


}


    public static Object removeMin(Vector v) {
        Reta r = (Reta) v.elementAt(0), r2;
        int z = 0, n = v.size();
        for (int j = 0; j < n; j++) {
            r2 = (Reta) v.elementAt(j);
            if (r.compareTo(r2) > 0) {
                z = j;
                r = r2;
            }
        }
        v.removeElementAt(z);
        return r;
    }

    
    
    