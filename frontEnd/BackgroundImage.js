import React from 'react';

const BackgroundImage = () => {
    const styles = {
        // no-repeat：不重复
        // center：X轴图像居中
        // center：Y轴图像居中
        // fixed：固定视窗
        background: `url('/images/background.png') no-repeat center center fixed`,
        backgroundSize: 'cover',  // 大小不变，在窗口大小变化时，多余的背景直接裁剪
        width: '100vw',  // 宽度占满
        height: '100vh',  // 高度占满
        position: 'relative',  // 允许在下面编写top、right、bottom、left等对图片背景进行偏移，作为背景时使用relative
    };

    return (
        // 在这里引入了背景图片，标签内都位于背景图上
        <div style={styles}>
        </div>
    );
};

export default BackgroundImage;
