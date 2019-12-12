@echo off

git add .
git commit -m "Blog update"
git push origin hexo

@echo git sync finished

hexo d -g

@echo hexo deployed&&generated finished

@pause
@pause
@pause

