import React from 'react';
import Fab from '@mui/material/Fab';
import { styled } from '@mui/material/styles';

// 中心悬浮图、内容内嵌均受imageWidth、imageHeight控制大小，受imageBorderRadius控制圆角；
// 中心悬浮图、内容内嵌受到CenterContainer约束居中；
// 中心悬浮图、内容内嵌受到ResponsiveFab约束响应式变化；

const imageWidth = 1303.7;  // 图像宽度
const imageHeight = 836.7;  // 图像高度
const imageBorderRadius = '1%';  // 圆角度设置


const CenterContainer = styled('div')({
    display: 'grid',  // 采用grid布局
    placeItems: 'center',  // 设置水平和垂直位置居中
    position: 'fixed',  // 固定位置
    top: 0,
    left: 0,
    width: '100%',
    height: '100%',
});


const ResponsiveFab = styled(Fab)(({ theme }) => ({
    padding: 0,  // 清除内边距
    borderRadius: imageBorderRadius,  // 设置圆角度，为1%
    boxShadow: '0px 4px 10px rgba(0, 0, 0, 0.3)',  // 设置阴影
    overflow: 'hidden',  // 防止内容溢出
    // pointerEvents: 'none',  // 取消点击功能
    [theme.breakpoints.down('xs')]: {  // 分辨率 ≤ xs 时响应式修改尺寸
        width: imageWidth * 0.2,
        height: imageHeight * 0.2,
    },
    [theme.breakpoints.up('sm')]: {  // 分辨率 ≥ sm 时响应式修改尺寸
        width: imageWidth * 0.4,
        height: imageHeight * 0.4,
    },
    [theme.breakpoints.up('md')]: {  // 分辨率 ≥ md 时响应式修改尺寸
        width: imageWidth * 0.6,
        height: imageHeight * 0.6,
    },
    [theme.breakpoints.up('lg')]: {  // 分辨率 ≥ lg 时响应式修改尺寸
        width: imageWidth * 0.8,
        height: imageHeight * 0.8,
    },
    [theme.breakpoints.up('xl')]: {  // 分辨率 ≥ xl 时响应式修改尺寸
        width: imageWidth,
        height: imageHeight,
    },
}));

const ResponsiveImg = styled('img')({
    width: '100%',
    height: '100%',
    objectFit: 'cover',
    borderRadius: imageBorderRadius,
    position: 'absolute',
    top: 0,
    left: 0,
    zIndex: -1,
});

const Content = styled('div')({
    width: '100%',
    height: '95.2%',
    overflowY: 'auto',
    marginTop:'2.9%',
    position: 'relative',
    zIndex: 1,
});

const InlaidFrame = () => {
    return (
        // 作为ResponsiveFab的父级容器，应用grid布局
        <CenterContainer>
            <ResponsiveFab aria-label="add">
                {/*背景图片*/}
                <ResponsiveImg
                    src="/images/page.png"
                    alt="page"
                    srcSet="/images/page.png 1x, /images/page@2x.png 2x, /images/page@3x.png 3x"
                />
                {/*镶嵌体*/}
                <Content>
                    {/*<p>这里是镶嵌的内容区域，可以显示文字、图片、视频等。</p>*/}
                </Content>
            </ResponsiveFab>
        </CenterContainer>
    );
};

export default InlaidFrame;
