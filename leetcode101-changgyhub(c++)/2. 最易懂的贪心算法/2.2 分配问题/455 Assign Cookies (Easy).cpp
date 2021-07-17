int findContentChildren(vector<int>& children, vector<int>& cookies) {
    sort(children.begin(), children.end());
    sort(cookies.begin(), cookies.end());
    int child = 0, cookie = 0;
    while (child < children.size() && cookie < cookies.size()) {
        if (children[child] <= cookies[cookie]) ++child;
        ++cookie;
    }
    return child;
}

// 双指针。
// 第n个孩子吃不饱的饼干可以跳过，因为第n+1个孩子也吃不饱。

// javascript
/**
 * @param {number[]} children
 * @param {number[]} cookies
 * @return {number}
 */
// var findContentChildren = function(children, cookies) {
//   children.sort((a, b) => a - b);
//   cookies.sort((a, b) => a - b);
//   let child = 0, cookie = 0;
//   while (child < children.length && cookie < cookies.length) {
//       if (children[child] <= cookies[cookie]) {
//           child++;
//       }
//       cookie++;
//   }
//   return child;
// };
