import React from 'react';
import Fab from '@mui/material/Fab';
import { styled } from '@mui/material/styles';

const imageWidth = 250;  // 图像宽度
const imageHeight = 250;  // 图像高度
const imageBorderRadius = '20%';  // 圆角度设置

// 配置悬浮框大小和位置
const ResponsiveFab = styled(Fab)(({ theme }) => ({
    position: 'fixed',  // 标识固定位置
    bottom: '2%',  // 将图片固定在距离底部2%的位置
    right: '2%',  // 将图片固定在距离右侧2%的位置
    padding: 0,  // 清除内边距
    minHeight: 'auto',  // 设置最小高度为自动
    minWidth: 'auto',  // 设置最小宽度为自动
    borderRadius: imageBorderRadius,  // 设置圆角度，为50%时呈圆形
    boxShadow: 'none',  // 移除阴影
    backgroundColor: 'transparent',  // 设置背景色为透明
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

const ResponsiveImg = styled('img')(({ theme }) => ({
    width: '100%',
    height: '100%',
    objectFit: 'cover',
    borderRadius: imageBorderRadius,
}));

const FloatingImage = () => {
    return (
        <ResponsiveFab aria-label="add">
            <ResponsiveImg src="/images/programmer.png" alt="programmer" />
        </ResponsiveFab>
    );
};

export default FloatingImage;
