#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
   std::vector<int> v1 = {1,2,3,4,5};
   // Print vector using forward iterators
   auto pv_fit = [&]() {
      for (std::vector<int>::iterator i = v1.begin();
           i < v1.end(); i++) {
         cout << " " << *i;
      }
   };
   // Print vector using backward iterators
   auto pv_bit = [&]() {
      for(auto ri = v1.rbegin();
          ri < v1.rend(); ri++) {
         cout << " " << *ri;
      }
   };

   cout << R"#(Vector iteration using "for(auto i : v)":)#";
   for (auto i : v1) {
      cout << " " << i;
   }
   cout << endl;
   cout << "Vector iteration using iterators:";
   pv_fit();
   cout << endl;
   pv_bit();
   cout << endl;
   cout << "Redimension vector to 9 elements all of them set to 3:";
   v1.assign(9, 3);
   pv_fit();
   cout << endl;
   pv_bit();
   cout << endl;
   cout << "Replaces vector with a subset of another vector:";
   std::vector<int> v2 = {100, 200, 300, 400, 500, 600, 700, 800, 900};
   v1.assign(v2.begin() + 2, v2.end() - 2);
   pv_fit();
   cout << endl;
   pv_bit();
   cout << endl;
   cout << "Replaces vector with another initializer list";
   v1.assign({11, 22, 33, 44, 55});
   pv_fit();
   cout << endl;
   pv_bit();
   cout << endl;
   return 0;
}
