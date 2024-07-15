// MulTextTyper.js
import React, { useState } from 'react';
import { Typewriter } from 'react-simple-typewriter';

const MulTextTyper = () => {
    // 定义第1、2行文本内容
    const line1text = ['Hi, Welcome!'];
    const line2text = ["I'm Ryan, a："];
    const line3text = [
        "Mechanical Engineer",
        "After-sales engineer",
        "Electrical engineer",
        "Web development engineer",
    ]

    // 获取第1、2行文本长度
    const textLengths = {
        line1TextLength: line1text[0].length,
        line2TextLength: line2text[0].length,
        line3TextLength: line3text[0].length,
    };

    // 设定第1、2行打字顺序
    const [line1Typing, setLine1Typing] = useState(true);
    const [line1TypingCursor, setLine1TypingCursor] = useState(true);
    const [line2Typing, setLine2Typing] = useState(false);
    const [line2TypingCursor, setLine2TypingCursor] = useState(false);
    const [line3Typing, setLine3Typing] = useState(false);
    const [line3TypingCursor, setLine3TypingCursor] = useState(false);

    // 监听第1、2行打字量，由line1increasing反馈
    const [line1QuantityOfTyping, setLine1QuantityOfTyping] = useState(0);
    const [line2QuantityOfTyping, setLine2QuantityOfTyping] = useState(0);

    // 检测第一行当前打字数量，Typewriter执行一次打字则由onType回调触发一次
    const line1increasing = (char) => {
        let tempCount1 = line1QuantityOfTyping + 1;
        // 打字量+1
        setLine1QuantityOfTyping(tempCount1);
        // 当前行完成打字后调用钩子（由长度确定），完成当前行，打字下一行
        if (tempCount1 === textLengths.line1TextLength) {
            // 设置1.5秒换行打字延迟
            setTimeout(() => {
                setLine1Typing(false);  //  第一行停止打印
                setLine1TypingCursor(false);  // 第一行光标停止闪烁
                setLine2Typing(true);  // 第二行光标显示
                setLine2TypingCursor(true);  // 第二行光标停止闪烁
            }, 1500)
        }
    };

    // 检测第二行当前打字数量
    const line2increasing = (char) => {
        let tempCount2 = line2QuantityOfTyping + 1
        setLine2QuantityOfTyping(tempCount2);
        if (tempCount2 === textLengths.line2TextLength) {
            setTimeout(() => {
                setLine2TypingCursor(false);
                setLine3Typing(true);
                setLine3TypingCursor(true);
            },1500)
        }
    };

    // 定义全局文本样式
    const styles = {
        container: {
            fontSize: '36px',  // 字体大小
            fontFamily: 'monospace',  // 字体
            display: 'flex',  // 启用flex布局
            height: '100vh',  // 设置flex布局范围为垂直方向全屏
            flexDirection: 'column',  // 定义flex布局以垂直方向为基准
            // alignItems: 'center',  // 应用flex布局，设置内部标签在水平方向居中
            // justifyContent: 'center',  // 应用flex布局，设置内部标签在垂直方向居中
            paddingLeft: '8%',  // 设置容器在水平方向的位置
            paddingTop: '20%',  // 设置容器在垂直方向的位置
        },
        // 第n行字体配置
        line1Styles: {
            fontSize: '36px',
            color: '#000000',  // 字体颜色
            margin: '-10px',  // 全局边距
            textTransform: 'none',
        },
        line2Styles: {
            fontSize: '36px',
            color: '#000000',
            margin: '-10px',
            textTransform: 'none',
        },
        line3Styles: {
            fontSize: '36px',
            color: '#000000',
            margin: '-10px',
            textTransform: 'none',
        }
    };

    return (
        <div style={styles.container}>
            <div style={styles.line1Styles}>
                <Typewriter
                    words={line1text}  // 文本内容
                    loop={1}  // 循环次数
                    cursor={line1TypingCursor}  // 光标显示状态
                    cursorStyle='|'  // 光标样式
                    typeSpeed={100}  // 打字速度
                    deleteSpeed={50}  // 删除速度
                    delaySpeed={1000000}  // 删除延迟时间
                    onType={line1increasing}  // 打字进行中回调函数
                />
            </div>
            <br />
            {line2Typing && (
                <div style={styles.line2Styles}>
                    <Typewriter
                        words={line2text}
                        loop={1}
                        cursor={line2TypingCursor}
                        cursorStyle='|'
                        typeSpeed={60}
                        deleteSpeed={50}
                        delaySpeed={1000000}
                        onType={line2increasing}
                    />
                    {line3Typing && (
                        <Typewriter
                            words={line3text}
                            loop
                            cursor={line3TypingCursor}
                            cursorStyle='|'
                            typeSpeed={65}
                            deleteSpeed={24}
                            delaySpeed={1000}
                        />
                    )}
                </div>
            )}
        </div>
    );
};

export default MulTextTyper;
