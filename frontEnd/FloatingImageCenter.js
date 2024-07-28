import React from 'react';
import Fab from '@mui/material/Fab';
import { styled } from '@mui/material/styles';

const imageWidth = 1303.7;  // 图像宽度
const imageHeight = 836.7;  // 图像高度
const imageBorderRadius = '1%';  // 圆角度设置

// 配置悬浮框大小和位置
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
    minHeight: 'auto',  // 设置最小高度为自动
    minWidth: 'auto',  // 设置最小宽度为自动
    borderRadius: imageBorderRadius,  // 设置圆角度，为50%时呈圆形
    boxShadow: '0px 4px 10px rgba(0, 0, 0, 0.3)',  // 移除阴影
    [theme.breakpoints.down('xs')]: {  // 分辨率 ≥ 0px 时响应式修改尺寸
        width: imageWidth * 0.2,
        height: imageHeight * 0.2,
    },
    [theme.breakpoints.up('sm')]: {  // 分辨率 ≥ 660px 时响应式修改尺寸
        width: imageWidth * 0.4,
        height: imageHeight * 0.4,
    },
    [theme.breakpoints.up('md')]: {  // 分辨率 ≥ 960px 时响应式修改尺寸
        width: imageWidth * 0.6,
        height: imageHeight * 0.6,
    },
    [theme.breakpoints.up('lg')]: {  // 分辨率 ≥ 1280px 时响应式修改尺寸
        width: imageWidth * 0.8,
        height: imageHeight * 0.8,
    },
    [theme.breakpoints.up('xl')]: {  // 分辨率 ≥ 1920px 时响应式修改尺寸
        width: imageWidth,
        height: imageHeight,
    },
}));

const ResponsiveImg = styled('img')({
    width: '100%',
    height: '100%',
    objectFit: 'cover',
    borderRadius: imageBorderRadius,
});

const FloatingImageCenter = () => {
    return (
        // 作为ResponsiveFab的父级容器，应用grid布局
        <CenterContainer>
            <ResponsiveFab aria-label="add">
                <ResponsiveImg
                    src="/images/page.png"
                    alt="page"
                    srcSet="/images/page.png 1x, /images/page@2x.png 2x, /images/page@3x.png 3x"
                />
            </ResponsiveFab>
        </CenterContainer>
    );
};

export default FloatingImageCenter;
