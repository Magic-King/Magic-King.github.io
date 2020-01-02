@echo off

git add .
git commit -m "Blog update"
git push origin hexo

@echo \ngit sync finished

hexo d -g

@echo hexo deployed&&generated finished

#@pause


