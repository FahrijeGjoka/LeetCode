#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<map>
#include<string>
#include<unordered_map>

using namespace std;

// Number of Students Unable to Eat Lunch
//Time complexity O(n)
//Space complexity O(1)
class queue_stack1 {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> studentqueue;

        for (int i = 0; i < students.size(); i++) {
            studentqueue.push(students.at(i));
        }

        int sandwichtop = 0;
        int studentswhoate = 0;
        int size = students.size();

        while (!studentqueue.empty()) {
            if (size == 0) {
                break;
            }

            int actualstudent = studentqueue.front();

            if (actualstudent == sandwiches[sandwichtop]) {
                studentqueue.pop();
                sandwichtop++;
                studentswhoate++;
                size = studentqueue.size();
            }
            else {
                studentqueue.pop();
                studentqueue.push(actualstudent);
                size--;
            }
        }
        return studentqueue.size();
    }
};

// Build an Array With Stack Operations
//Time complexity O(n)
//Space complexity O(n)
class queue_stack2 {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        stack<string> st;
        vector<string> v;
        int t = 0;
        for (int i = 1; i <= n && t < target.size(); i++) {
            if (target[t] == i) {
                st.push("Push");
                t++;
            }
            else {
                st.push("Push");
                st.push("Pop");
            }
        }

        int s = st.size();

        for (int i = 0; i < s; i++) {
            v.push_back(st.top());
            st.pop();
        }

        reverse(v.begin(), v.end());

        return v;
    }
};

//Climbing Stairs
//Time complexity O(1)
//Space complexity O(n)
class queue_stack3 {
public:
    int climbStairs(int n) {
        if (n <= 3) return n;

        int parafundit = 3;
        int pparafundit = 2;
        int aktualja = 0;

        for (int i = 3; i < n; i++) {
            aktualja = parafundit + pparafundit;
            pparafundit = parafundit;
            parafundit = aktualja;
        }

        return aktualja;
    }
};

// Implement Stack using Queues
//Time complexity O(n)
//Space complexity O(1)
class queue_stack4 {
private:
    queue<int> q;

public:
    queue_stack4() {}

    void push(int x) {
        q.push(x);
        for (int i = 0; i < q.size() - 1; ++i) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int value = q.front();
        q.pop();
        return value;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

//Implement Queue using Stacks
//Time complexity O(n)
//Space complexity O(n)
class queue_stack5 {
    stack<int> s1;
    stack<int> s2;
public:
    queue_stack5() {}

    void push(int x) {
        s1.push(x);
    }

    int pop() {
        int value;
        while (!s1.empty()) {
            value = s1.top();
            s2.push(value);
            s1.pop();
        }
        s2.pop();
        int last = value;
        while (!s2.empty()) {
            value = s2.top();
            s2.pop();
            s1.push(value);
        }
        return last;
    }

    int peek() {
        int value;
        while (!s1.empty()) {
            value = s1.top();
            s2.push(value);
            s1.pop();
        }
        int last = value;
        while (!s2.empty()) {
            value = s2.top();
            s2.pop();
            s1.push(value);
        }
        return last;
    }

    bool empty() {
        return s1.empty();
    }
};
//Linked List Cycle
//Time complexity O(n)
//Space complexity O(1)
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class list1 {
public:
    bool hasCycle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow) {
                return true;
            }
        }
        return false;
    }
};

// Reverse Linked List
//Time complexity O(n)
//Space complexity O(1)
void printList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}
class list2 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while (curr) {
            ListNode* nextCopy = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextCopy;
        }
        return prev;
    }
};

// Remove Duplicates from Sorted List
//Time complexity O(n)
//Space complexity O(1)
class list3 {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }

        ListNode* prev = head;
        ListNode* temp = prev->next;

        while (temp != nullptr) {
            if (temp->val == prev->val) {
                prev->next = temp->next;
            }
            else {
                prev = temp;
            }
            temp = temp->next;
        }

        return head;
    }
};

// Palindrome Linked List
//Time complexity O(n)
//Space complexity O(1)
ListNode* createLinkedList(const std::vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* current = head;
    for (size_t i = 1; i < vals.size(); ++i) {
        current->next = new ListNode(vals[i]);
        current = current->next;
    }
    return head;
}

void deleteLinkedList(ListNode* head) {
    while (head != nullptr) {
        ListNode* next = head->next;
        delete head;
        head = next;
    }
}
class list4 {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> v;
        while (head != nullptr) {
            v.push_back(head->val);
            head = head->next;
        }
        int n = v.size();
        int i = 0, j = n - 1;
        while (i < j) {
            if (v[i] != v[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};

//Remove Linked List Elements
//Time Complexity:O(n)
//Space Complexity:O(1)
void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}
class list5 {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* temp = new ListNode(0);
        temp->next = head;
        ListNode* curr = temp;
        while (curr->next != NULL) {
            if (curr->next->val == val) {
                curr->next = curr->next->next;
            }
            else {
                curr = curr->next;
            }
        }
        return temp->next;
    }
};

//Roman to integer
//Time Complexity:O(n)
//Space Complexity:O(1)
class hashtable1 {
public:
    int romanToInt(string s) {
        map<char, int> roman;
        roman.insert(make_pair('I', 1));
        roman.insert(make_pair('V', 5));
        roman.insert(make_pair('X', 10));
        roman.insert(make_pair('L', 50));
        roman.insert(make_pair('C', 100));
        roman.insert(make_pair('D', 500));
        roman.insert(make_pair('M', 1000));

        int gjatesia = s.length(), num, sum = 0;
        for (int i = 0; i < gjatesia; ) {
            if (i == (gjatesia - 1) || (roman[s[i]] >= roman[s[i + 1]])) {
                num = roman[s[i]];
                i++;
            }

            else {
                num = roman[s[i + 1]] - roman[s[i]];
                i += 2;
            }

            sum += num;
        }
        return sum;
    }
};
//happyNumber
//Time Complexity:O(2n)
//Space Complexity:O(m)
class hashtable2 {
public:
    int square(int& x) {
        int sq = 0;
        while (x > 0) {
            int temp = 0;
            temp = x % 10;
            sq += temp * temp;
            x = x / 10;
        }
        return sq;
    }
    bool isHappy(int n) {
        unordered_map<int, int> m;
        while (n != 1) {
            m[n]++;
            if (m[n] > 1)
                break;
            n = square(n);
        }
        if (n == 1) return true;
        return false;
    }
};

//contains duplicate
//Time Complexity:O(n)
//Space Complexity:O(m)
class hashtable3 {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
            if (freq[nums[i]] > 1) {
                return true;
            }
        }
        return false;
    }
};
//Missing number
//Time Complexity:O(n)
//Space Complexity:O(1)
class hashtable4 {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int curr = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += i + 1;
            curr += nums[i];
        }
        return sum - curr;
    }
};

//N-repeated element size in 2n array
//Time Complexity:O(n)
//Space Complexity:O(m)
class hashtable5 {
public:
    int repeatedNTimes(std::vector<int>& a) {
        int n = a.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
            mp[a[i]]++;

        for (auto it = mp.begin(); it != mp.end(); ++it) {
            if (it->second >= n / 2)
                return it->first;
        }
        return 0;
    }
};

//Guess Number Higher or Lower
//Time Complexity:O(logn)
//Space Complexity:O(1)
int pickedNumber;
int guess(int num) {
    if (num < pickedNumber) return 1;
    if (num > pickedNumber) return -1;
    return 0;
}
class bst1 {
public:
    int guessNumber(int n) {
        int left = 1;
        int right = n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int result = guess(mid);
            if (result == 0) {
                return mid;
            }
            else if (result == -1) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return -1;
    }
};

 
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 //Count Complete Tree Nodes
 //Time Complexity:O(log^2n)
 //Space Complexity:O(logn)
class bst2 {
public:
    int countNodes(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        TreeNode* left = root;
        TreeNode* right = root;

        int height_left = 0;
        int height_right = 0;
        while (left) {
            height_left++;
            left = left->left;
        }

        while (right) {
            height_right++;
            right = right->right;
        }

        if (height_left == height_right) {
            return pow(2, height_left) - 1;
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

//Count Negative numbers in a sorted matrix
//Time Complexity:O(m*n)
//Space Complexity:O(1)
class bst3 {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int rreshti = grid.size();
        int kolona = grid[0].size();
        int negative = 0;
        for (int i = 0; i < rreshti; i++) {
            for (int j = 0; j < kolona; j++) {
                if (grid[i][j] < 0) {
                    negative++;
                }
            }
        }
        return negative;
    }
};

//Binary Search
//Time Complexity:O(logn)
//Space Complexity:O(1)
class bst4 {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return -1;
    }
};
//Check if N and its double exist
//Time Complexity:O(n^2)
//Space Complexity:O(1)
class bst5 {
public:
    bool checkIfExist(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                if (arr[i] == 2 * arr[j] || arr[j] == 2 * arr[i])
                    return 1;
            }
        }
        return 0;
    }

};


int main() {

    int choice;
    cout << "Choose a function (1-20): ";
    cin >> choice;

    switch (choice) {
    case 1:
    {
        vector<int> students = { 1, 1, 1, 0, 0, 1 };
        vector<int> sandwiches = { 1,0 ,0 , 0, 1, 1 };

        queue_stack1 mensa;
        int no_of_students_who_ate = mensa.countStudents(students, sandwiches);

        cout << no_of_students_who_ate << endl;
        break;
    }

    case 2: {
        queue_stack2 solution;
        vector<int> buildarray = { 1, 3 };
        int n = 3;
        vector<string> result = solution.buildArray(buildarray, n);

        cout << "Operations: " << endl;
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }

    case 3: {
        queue_stack3 sol;

        int n = 5;
        int result = sol.climbStairs(5);

        cout << "Number of distinct ways to climb " << n << " steps: " << result << endl;

        n = 2;
        result = sol.climbStairs(2);
        cout << "Number of distinct ways to climb " << n << " steps: " << result << endl;
        break;
    }

    case 4: {
        queue_stack4 stack;

        stack.push(1);
        stack.push(2);
        stack.push(3);

        cout << "Top element: " << stack.top() << endl;
        cout << "Popping: " << stack.pop() << endl;
        cout << "Top element after popping: " << stack.top() << endl;

        cout << "Is the stack empty? " << (stack.empty() ? "Yes" : "No") << endl;
        break;
    }

    case 5: {
        queue_stack5 queue;

        queue.push(1);
        queue.push(2);
        queue.push(3);

        cout << "Front element: " << queue.peek() << endl;
        cout << "Popping: " << queue.pop() << endl;
        cout << "Front element after popping: " << queue.peek() << endl;

        cout << "Is the queue empty? " << (queue.empty() ? "Yes" : "No") << endl;
    }

    case 6: {
        ListNode* head = new ListNode(3);
        ListNode* second = new ListNode(2);
        ListNode* third = new ListNode(0);
        ListNode* fourth = new ListNode(-4);

        head->next = second;
        second->next = third;
        third->next = fourth;

        fourth->next = second;

        list1 solution;
        if (solution.hasCycle(head)) {
            cout << "true" << endl;
        }
        else {
            cout << "false" << endl;
        }

        fourth->next = nullptr;

        ListNode* current = head;
        while (current != nullptr) {
            ListNode* next = current->next;
            delete current;
            current = next;
        }
        break;
    }

    case 7: {
        ListNode* head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->next = new ListNode(3);
        head->next->next->next = new ListNode(4);
        head->next->next->next->next = new ListNode(5);

        cout << "Original list: ";
        printList(head);

        list2 solution;
        ListNode* reversedHead = solution.reverseList(head);

        cout << "Reversed list: ";
        printList(reversedHead);

        ListNode* current = reversedHead;
        while (current != nullptr) {
            ListNode* next = current->next;
            delete current;
            current = next;
        }
        break;
    }

    case 8: {
        ListNode* head = new ListNode(1);
        head->next = new ListNode(1);
        head->next->next = new ListNode(2);
        head->next->next->next = new ListNode(3);
        head->next->next->next->next = new ListNode(3);

        cout << "Original list: ";
        printList(head);

        list3 solution;
        ListNode* result = solution.deleteDuplicates(head);

        cout << "List after removing duplicates: ";
        printList(result);

        ListNode* current = result;
        while (current != nullptr) {
            ListNode* next = current->next;
            delete current;
            current = next;
        }
        break;
    }

    case 9: {
        vector<int> vals = { 1, 2, 2, 1 };
        ListNode* head = createLinkedList(vals);

        list4 solution;
        bool result = solution.isPalindrome(head);

        cout << "Is palindrome: " << (result ? "true" : "false") << endl;

        deleteLinkedList(head);
        break;
    }

    case 10: {
        vector<int> vals = { 1, 2, 6, 3, 4, 5, 6 };
        ListNode* head = createLinkedList(vals);

        cout << "Original list: ";
        printLinkedList(head);

        list5 solution;
        int valToRemove = 6;
        head = solution.removeElements(head, valToRemove);

        cout << "List after removing " << valToRemove << ": ";
        printLinkedList(head);

        deleteLinkedList(head);

        break;
    }

    case 11: {
        hashtable1 solution;
        string romanNumeral;

        cout << "Enter a Roman numeral: ";
        cin >> romanNumeral;

        int result = solution.romanToInt(romanNumeral);
        cout << "The integer value of " << romanNumeral << " is " << result << endl;

        break;
    }

    case 12: {
        hashtable2 solution;
        int number;

        cout << "Enter a number: ";
        cin >> number;

        bool result = solution.isHappy(number);
        if (result) {
            cout << number << " is a happy number." << std::endl;
        }
        else {
            cout << number << " is not a happy number." << std::endl;
        }
        break;
    }

    case 13: {
        hashtable3 solution;
        vector<int> nums;
        int n, element;

        cout << "Enter the number of elements in the array: ";
        cin >> n;

        cout << "Enter the elements of the array: ";
        for (int i = 0; i < n; i++) {
            cin >> element;
            nums.push_back(element);
        }

        bool result = solution.containsDuplicate(nums);
        if (result) {
            cout << "The array contains duplicate elements." << endl;
        }
        else {
            cout << "The array does not contain any duplicate elements." << endl;
        }
        break;
    }

    case 14: {
        hashtable4 solution;
        vector<int> nums;
        int n, element;

        cout << "Enter the number of elements in the array: ";
        cin >> n;

        cout << "Enter the elements of the array: ";
        for (int i = 0; i < n; i++) {
            cin >> element;
            nums.push_back(element);
        }

        int missingNumber = solution.missingNumber(nums);
        cout << "The missing number in the array is: " << missingNumber << endl;

        break;
    }

    case 15: {
        hashtable5 solution;
        vector<int> a = { 1, 2, 3, 3, 3, 4 }; 
        int repeatedNumber = solution.repeatedNTimes(a);
        cout << "The repeated number is: " << repeatedNumber <<endl;
        break;
    }

    case 16: {
        bst1 solution;
        int n = 100;
        pickedNumber = 73;

        int guessedNumber = solution.guessNumber(n);
        cout << "The guessed number is: " << guessedNumber << endl;
        break;
    }
     
    case 17: {
        TreeNode* root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        root->left->left = new TreeNode(4);
        root->left->right = new TreeNode(5);
        root->right->left = new TreeNode(6);

        bst2 solution;
        int nodeCount = solution.countNodes(root);
        cout << "The number of nodes in the complete binary tree is: " << nodeCount << endl;
        break;
    }

    case 18: {
     vector<vector<int>> grid = {
                                 { 4,  3,  2, -1},
                                 { 3,  2,  1, -1},
                                 { 1,  1, -1, -2},
                                 {-1, -1, -2, -3}
                                 };

        bst3 solution;
        int count = solution.countNegatives(grid);
        cout << "The number of negative numbers in the grid is: " << count << endl;
    }

    case 19: {
        vector<int> nums = { -1, 0, 3, 5, 9, 12 };
        int target = 9;

        bst4 solution;
        int result = solution.search(nums, target);
        if (result != -1) {
            cout << "Target " << target << " found at index " << result << endl;
        }
        else {
            cout << "Target " << target << " not found in the array." << endl;
        }
        break;
    }

    case 20: {
        vector<int> arr = { 10, 2, 5, 3 };

        bst5 solution;
        bool result = solution.checkIfExist(arr);
        if (result) {
            cout << "There exists an element and its double in the array." << endl;
        }
        else {
            cout << "There does not exist an element and its double in the array." << endl;
        }
    }

    default:
        cout << "Invalid choice." << endl;
    }

    return 0;
}