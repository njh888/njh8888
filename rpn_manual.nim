# rpn_manual.nim
import nimib

nbInit

nbText: "# RPN计算器使用手册"

nbText: "## 简介"
nbText: "逆波兰表示法（Reverse Polish Notation，RPN）计算器，使用C++实现，支持基础四则运算和高级数学函数。"

nbText: "## 安装和编译"

nbText: "### 编译命令："
nbCode:
  echo "g++ -std=c++11 -o rpn_calc rpn_calc.cpp"

nbText: "### 运行程序："
nbCode:
  echo "./rpn_calc"

nbText: "## 基本使用示例"

nbCode:
  echo "示例输入和输出："
  echo "输入: '5 5 +'"
  echo "输出: 结果: 10"
  echo ""
  echo "输入: '1 2 + 3 + 7 7 * +'"
  echo "输出: 结果: 55"
  echo ""
  echo "输入: '16 sqrt'"
  echo "输出: 结果: 4"
  echo ""
  echo "输入: '5 fib'"
  echo "输出: 结果: 5"

nbText: "## 支持的操作符"

nbText: "### 基础运算"
nbText: "- `+` - 加法：`a b +` → a + b"
nbText: "- `-` - 减法：`a b -` → a - b"  
nbText: "- `*` - 乘法：`a b *` → a × b"
nbText: "- `/` - 除法：`a b /` → a ÷ b"

nbText: "### 高级运算"
nbText: "- `sqrt` - 平方根：`a sqrt` → √a"
nbText: "- `^` - 幂运算：`a b ^` → aᵇ"
nbText: "- `fib` - 斐波那契数：`n fib` → 第n个斐波那契数"

nbText: "### 栈操作命令"
nbText: "- `clear` - 清空栈"
nbText: "- `show` - 显示当前栈内容"
nbText: "- `history` - 显示计算历史"
nbText: "- `help` - 显示帮助信息"
nbText: "- `q` - 退出程序"

nbText: "## 错误处理"

nbText: "### 常见错误类型"
nbText: "- **栈空错误**: 当尝试从空栈弹出元素时发生"
nbText: "- **操作数不足**: 当运算需要更多操作数时发生"
nbText: "- **除零错误**: 除法运算中除数为零"
nbText: "- **无效输入**: 输入了未知操作符或格式错误的数字"

nbText: "## 批量计算"
nbText: "支持在单行输入完整的RPN表达式："
nbCode:
  echo "> 3 4 5 * + 2 -"
  echo "结果: 21"

nbText: "计算过程："
nbText: "1. 3 → 栈: [3]"
nbText: "2. 4 → 栈: [3, 4]"
nbText: "3. 5 → 栈: [3, 4, 5]"
nbText: "4. * → 栈: [3, 20] (4*5=20)"
nbText: "5. + → 栈: [23] (3+20=23)"
nbText: "6. 2 → 栈: [23, 2]"
nbText: "7. - → 栈: [21] (23-2=21)"

nbSave
