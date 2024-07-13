// npm install react-simple-typewriter 
import React, { useState } from 'react';
import { Typewriter } from 'react-simple-typewriter';

const MulTextTyper = () => {
    // 定义第1、2行文本内容
    const line1text = ['Hi, Welcome!'];
    const line2text = ["I'm Ryan a"];

    // 获取第1、2行文本长度
    const textLengths = {
        line1TextLength: line1text[0].length,
        line2TextLength: line2text[0].length
    };

    // 设定第1、2行打字顺序
    const [line1Typing, setLine1Typing] = useState(true);
    const [line2Typing, setLine2Typing] = useState(false);

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
                setLine1Typing(false);  //  第一行光标隐藏
                setLine2Typing(true);  // 第二行光标显示
            }, 1500)
        }
    };

    // 检测第二行当前打字数量
    const line2increasing = (char) => {
        let tempCount2 = line2QuantityOfTyping + 1
        setLine2QuantityOfTyping(tempCount2);
    };

    // 定义全局文本样式
    const styles = {
        container: {
            fontSize: '24px',  // 字体大小
            fontFamily: 'monospace',  // 字体
            display: 'flex',  // 启用flex布局
            height: '100vh',  // 设置flex布局范围为垂直方向全屏
            flexDirection: 'column',  // 定义flex布局以垂直方向为基准
            alignItems: 'center',  // 应用flex布局，设置内部标签在水平方向居中
            justifyContent: 'center',  // 应用flex布局，设置内部标签在垂直方向居中
        },
        // 第n行字体配置
        line1Styles: {
            fontSize: '24px',
            color: '#000000',  // 字体颜色
            margin: '-10px',  // 全局边距
            // marginTop: '-10px', // 顶边距
            // marginBottom: '-10px'  // 底边距
            // textAlign: 'left'  // 居左
            // textAlign: 'left'  // 居右
            // textAlign: 'center'  // 居中
        },
        line2Styles: {
            fontSize: '24px',
            color: '#000000',
            margin: '-10px',
            // marginTop: '-10px',
            // marginBottom: '-10px'
            // textAlign: 'left'  // 居左
            // textAlign: 'left'  // 居右
            // textAlign: 'center'  // 居中

        }
    };

    return (
        <div style={styles.container}>
            <div style={styles.line1Styles}>
                <Typewriter
                    words={line1text}  // 文本内容
                    loop={1}  // 循环次数
                    cursor={line1Typing}  // 光标显示状态
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
                        cursor={line2Typing}
                        cursorStyle='|'
                        typeSpeed={100}
                        deleteSpeed={50}
                        delaySpeed={1000000}
                        onType={line2increasing}
                    />
                </div>
            )}
        </div>
    );
};

export default MulTextTyper;
