@echo off
git add .
git commit -m "Blog update"
git push origin hexo

hexo d -g

pause