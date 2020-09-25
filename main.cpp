#include <iostream>
#include <vector>
using namespace std;
/*Given an array of meeting time intervals consisting of start and end times
[[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

Example 1:
Input: [[0, 30],[5, 10],[15, 20]]
Output: 2

Example 2:
Input: [[7,10],[2,4]]
Output: 1

 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 *
 */
class interval {
public:
    int start;
    int end;
    interval(){start=0;end=0;}
    interval(int s=0, int e=0):start(s),end(e){};//constructor and initializer
    void modify(int s, int e){start = s; end = e;}
};
void sort(vector<interval>a){

}

int meeting_rooms_needed(vector<interval> a){
    vector<int> rooms(0);
    //first step, sort the list by starting time
    sort(a);//needs to write algorithms for sorting the vector using start of the object.
    //second, going through the list, for each interval, going through room list and see
    // if this room's start time is later than any room's end time. If there
    // is, update the interval's end time to the room.
    // When all existing rooms are full (end time is bigger than new-coming meeting's start time),
    // we add one extra room.
    if(a.size()!=0)
        rooms.push_back(a[0].end);//put the first meeting in, and we do it out of loop
        // so that we do not need to check it every time.
    for(int i=1;i<a.size();i++){//iterating through the intervals
        bool found_the_room = false;
        for(int j=0;j<rooms.size();j++){//iterating through all the rooms
            if(a[i].start>rooms[j]){
                rooms[j]=a[i].end;
                found_the_room=true;
            }
        }
        if(!found_the_room)
            rooms.push_back(a[i].end);
    }
    return rooms.size();//return the number of rooms.
}
int main() {
    vector<interval> a;
    interval aa(1,3);
    interval b(2,8);
    interval c(4,5);
    interval d(5,7);
    interval e(6,10);
    interval f(9,11);
    a.push_back(aa);
    a.push_back(b);
    a.push_back(c);
    a.push_back(d);
    a.push_back(e);
    a.push_back(f);
    int result = meeting_rooms_needed(a);
    cout<<result;
    return 0;
}
