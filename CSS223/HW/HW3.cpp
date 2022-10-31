// Multi-column-sorting

#include <vector>
#include <iostream>
#include <algorithm>

using Matrix = std::vector<std::vector<int>>;
using Column = std::vector<int>;

Column max_col(const Matrix &v) {
    return *std::max_element(v.begin(), v.end(),
                            [](auto& lhs, auto& rhs)
                            {
                                return lhs.size() < rhs.size();
                            });
}

bool is_element_in_next_rows(const Matrix &v, int element,int row) {
    for (auto& col : v) {
        if (row >= static_cast<int>(col.size())) continue; // Out of range
        if (std::lower_bound(col.begin()+row+1,col.end(),element) != 
            std::upper_bound(col.begin()+row+1,col.end(),element)) {
            return true;
        }
    }
    return false;
}

int min_element_in_row(const Matrix &v, int row) { 
    int min_element = max_col(v)[row];
    for (auto& col : v) {
        if (row >= static_cast<int>(col.size())) continue; // Out of range
        if (col[row] != 0) min_element = std::min(min_element, col[row]);
    }
    return min_element;
}

void print_elements(const Matrix &v) {
    for (auto& i : v) {
        for (auto& j : i) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}

void organize_elements(Matrix &v) {
    for (auto& col : v) {
        std::sort(col.begin(),col.end());
    }
    auto current_max_col = max_col(v);
    for (int row{0}; current_max_col.begin()+row!=current_max_col.end(); ++row) {
        int min_element = min_element_in_row(v,row);
        for(auto& col : v) {
            if (row >= static_cast<int>(col.size())) continue; // Out of range
            int candidate = col[row];
            if (candidate > min_element) {
                if (is_element_in_next_rows(v,candidate,row)) {
                    col.push_back(0);
                    std::rotate(col.begin()+row,col.end()-1,col.end());
                }
            }
        }
        current_max_col = max_col(v);
    }
}

int main() {

    Column c1 = {1,3,4,2,3,4,1,2,3,1,1,4,5,3};
    Column c2 = {1,1,4,4,5,3,3,4,3,5,1,1,2,5};
    Column c3 = {4,1,4,4,3,3,3,3,5,3,4,1,3,2};

    Matrix v;
    v.push_back(c1);
    v.push_back(c2);
    v.push_back(c3);

    std::cout << "Original: \n";
    print_elements(v);
    organize_elements(v);
    std::cout << "Organized: \n";
    print_elements(v);
    return 0;
}