#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};

bool mycomp(Segment a, Segment b){ return (a.end<b.end);}

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  vector<int> result;
  int position=0;
  std::sort(segments.begin(),segments.end(),mycomp);
  for (size_t i = 0; i < segments.size(); ++i) {
    points.push_back(segments[i].start);
    points.push_back(segments[i].end);
  }
  result.push_back(-1);
  for (size_t i=0;i<segments.size();++i){
	    
	  if(result[position]<points[2*i]) {
		result.push_back(points[2*i+1]);
		position++;
	  }
  }


		

  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size()-1 << "\n";
  for (size_t i = 1; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
