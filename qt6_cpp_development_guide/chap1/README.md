# 第一章：认识Qt

## Qt简介
- 跨平台应用程序开发框架
- 首次发布于1995年5月
- qt官网：www.qt.io

## 跨平台开发能力
|  目标设备  |       目标平台       |          主机平台          |
| :--------: | :------------------: | :------------------------: |
|            |      桌面Linux       |         桌面Linux          |
|   计算机   |        macOS         |           macOS            |
|            |       Windows        |          Windows           |
|            |       Android        | 桌面Linux、 macOS、Windows |
|  移动设备  |         iOS          |           macOS            |
|            |     手机Windows      |          Windows           |
|            |     嵌入式Linux      |         桌面Linux          |
| 嵌入式设备 |         QNX          |    桌面Linux、 Windows     |
|            |       VxWorks        |    桌面Linux、 Windows     |
|            |    嵌入式Windows     |          Windows           |
|   单片机   | FreeRTOS或无操作系统 |    Windows、 桌面Linux     |

Qt 源代码编译后生成目标平台的原生二进制代码，不像Java那样需要虚拟机，运行效率更高。

## Qt许可的类型
Qt 的许可类型
- 商业许可：按年付费。模块更多，开发者可以不公开自己的源码。
- 开源许可：
  - GPLv2 / GPLv3 许可：使用了 GLP 许可的 Qt 代码允许销售，但必须开源。 GPLv3还要求公开相关硬件信息。
  - LGPLv3 许可：与 GPL 类似，但更宽松。若只是链接或调用 GPL 许可协议的 Qt 代码，可以不开源。

## 安装包
Qt 安装包：根据目标设备不同，提供了不同的安装包。

个人推荐：手动选择组件编译安装Qt。详见[Qt源码编译](https://mister-kin.github.io/code/qt/#Qt源码编译)。

## Qt支持的开发语言
1. C++ 和 QML
   - Qt 对标准C++语言进行了扩展，引入了信号与槽等机制。
   - QML （ Qt Meta Language） 是一个用来描述应用程序界面的声明式脚本语言。
   - C++和QML可以混合使用。
2. Python
   - Qt C++可以被转换Python绑定，使用 Python 调用 Qt 类库进行GUI程序开发。
   - 常用的 Qt 类库 Python 绑定有： PyQt （GPLv3 许可）和 PySide （LGPLv3 许可）

## Qt6新特性
2020 年 12 月正式发布了 Qt6.0 ，引入的主要新特性包括：
- 支持 C++ 17 标准。
- Qt 核心库的改动：新的属性和绑定系统；全面支持Unicode 字符串；修改了 QList 的实现方式，将 QVector 类和 QList 类统一为 QList 类； QMetaType 和 QVariant 几乎被重写。
- 新的图形架构： Qt5 中 3D 渲染依赖 0penGL。Qt6 中引入了新的技术 RHI （rendering hardware interface），它是一个抽象层，使得 Qt 可以使用平台本地化的 3D 图形 API（Linux：Vulkan 、Windows：Direct 3D、macOS：Metal）。
- CMake 构建系统： Qt6 仍然支持 qmake，但建议使用 CMake。
- 其他（多媒体、网络、 Qt Quick 3D 等模块的改进）。
