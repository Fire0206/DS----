@echo off
cd /d D:\OneDrive\桌面\编程
echo ================================
echo  Git 一键提交并推送脚本
echo ================================
set /p msg=请输入提交说明: 

git add .
git commit -m "%msg%"
git push origin master

echo ================================
echo   已完成提交和推送！
echo ================================
pause
