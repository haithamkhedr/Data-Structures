#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::swap;
using std::pair;
using std::make_pair;

class HeapBuilder {
 private:
  vector<int> data_;
  vector< pair<int, int> > swaps_;
  void WriteResponse() const {
    cout << swaps_.size() << "\n";
    for (int i = 0; i < swaps_.size(); ++i) {
      cout << swaps_[i].first << " " << swaps_[i].second << "\n";
    }
  }
    void writeHeap() const{
        for (int i = 0; i < data_.size(); ++i) {
            cout << data_[i] << " ";
        }
        cout<< std::endl;
    }

  void ReadData() {
    int n;
    cin >> n;
    data_.resize(n);
    for(int i = 0; i < n; ++i)
      cin >> data_[i];
  }
    int parent(int i){
        return (i-1)/2;
    }
    int leftChild(int i){
        return 2*i+1 > data_.size() - 1 ? i: 2*i+1;
        
    }
    int rightChild(int i){
        return 2*i+2 > data_.size() - 1 ? i: 2*i+2;
    }
    void siftDown(int i){
        int l_child = leftChild(i);
        int r_child = rightChild(i);
        if((data_[i] <= data_[l_child] && data_[i] <= data_[r_child])){
            return;
        }
        else{
            int swap_idx = l_child;
            if(data_[r_child] < data_[l_child]){
                swap_idx = r_child;
            }
            if(swap_idx != i){
                swap(data_[i], data_[swap_idx]);
                swaps_.push_back(make_pair(i, swap_idx));
                siftDown(swap_idx);
            }
        }
    }
  void GenerateSwaps() {
    swaps_.clear();
    // The following naive implementation just sorts 
    // the given sequence using selection sort algorithm
    // and saves the resulting sequence of swaps.
    // This turns the given array into a heap, 
    // but in the worst case gives a quadratic number of swaps.
    //
    // TODO: replace by a more efficient implementation
      int lastParent = parent(data_.size() -1 );
      for(int i = lastParent; i >= 0; --i){
          siftDown(i);
      }
  }

 public:
  void Solve() {
    ReadData();
    GenerateSwaps();
    WriteResponse();
      //writeHeap();
  }
};
int main() {
  std::ios_base::sync_with_stdio(false);
  HeapBuilder heap_builder;
  heap_builder.Solve();
  return 0;
}
