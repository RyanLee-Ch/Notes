// WelcTyper.js
import React, { useState } from 'react';
import { Typewriter } from 'react-simple-typewriter';

const App = () => {
    const [count1, setCount1] = useState(0);
    const [count2, setCount2] = useState(0);
    const [line1Typing, setLine1Typing] = useState(true);
    const [line2Typing, setLine2Typing] = useState(false);

    const line1text = ['Hi, Welcome!'];  // 修改第一行内容
    const line2text = ["I'm Ryan a"];  // 修改第二行内容
    const textLengths = {
        line1TextLength: line1text[0].length,  // 获取第一行文本长度
        line2TextLength: line2text[0].length   // 获取第二行文本长度
    };

    // 检测第一行当前打字数量
    const handle_1lineIncrease = (char) => {
        let tempCount1 = count1 + 1;
        setCount1(tempCount1);
        // 当前行完成打字后调用钩子（由长度确定）
        if (tempCount1 === textLengths.line1TextLength) {
            setLine1Typing(false);  //  第一行光标隐藏
            setLine2Typing(true);  // 第二行光标显示
        }
    };

    // 检测第二行当前打字数量
    const handle_2lineIncrease = (char) => {
        let tempCount2 = count2 + 1
        setCount2(tempCount2);
    };


    return (
        <div style={{ fontSize: '24px', fontFamily: 'monospace' }}>
            <Typewriter
                words={line1text}
                loop={1}
                cursor={line1Typing}
                cursorStyle='|'
                typeSpeed={100}
                deleteSpeed={50}
                delaySpeed={100}
                onType={handle_1lineIncrease}  // 打字进行中回调函数
            />
            <br />
            {line2Typing && (
                <Typewriter
                    words={line2text}
                    loop={1}
                    cursor={line2Typing}
                    cursorStyle='|'
                    typeSpeed={100}
                    deleteSpeed={50}
                    delaySpeed={1000}
                    onType={handle_2lineIncrease}
                />
            )}
        </div>
    );
};

export default App;
