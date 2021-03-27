# 建立git
#### （1）安装git
#### （2）建立版本库
> \$ mkdir (文件名)
> \$ cd (文件名)
> \$ pwd

然后使用
> git init
#### （3）添加文件的到版本库
1. 用 **git add （文件名）**,添加的到仓库
> git add first.txt

2. 用 ***git commit -m"修改的内容"*** 将文件提交到仓库
> git commit -m"change some words"

#### (4)查看仓库的当前状态(是否工作区有内容)
> git status

#### （5）查看修改的内容
> git diff (文件名)

**查看工作区与版本库的最新版本之间的区别：**
>git diff HEAD -- 文件名
#### （6）查看文件的历史纪录
> git log

 **有（HEAD -> master）的即为当前版本**
 如果要输出信息更整洁 要用参数 **--pretty = oneline**
 > git log --pretty=oneline

#### （7）版本之间的切换
> git reset --hard 参数

**参数说明**：在Git中，用HEAD表示当前版本，上一个版本就是HEAD^， 上上一个版本就是HEAD^^， 当然往上100个版本写100个^比较容易数不来，所以写成HEAD\~100。（参数也可以写为要跳转的版本信息~~一坨神秘代码~~的前5位）

### （8）查看命令的历史
> git reflog

### (9)撤销修改
第一种情况：还在工作区
>git checkout -- 文件名

丢掉工作区全部的修改内容，还原为最后一次调用<u>git add</u>或<u>git commit</u>的状态

****
第二种情况：修改后的内容已经用<u>git add</u>从工作区拉到了暂存区，使用
>git reset HEAD 文件名

将暂存区的修改撤销，重新放回工作区

####（8）删除与恢复
普通删除
> rm 文件名

删除版本库的内容
> git rm 文件名

#####1. 彻底删除步骤：
第一步：git rm 文件名
第二步：git commit -m"remove 文件名"

#####2. 恢复步骤：
**情况一**：工作区文件删除，无其他操作

1. rm test.txt

以下命令可恢复文件

1. git checkout -- test.txt

**情况二**：工作区文件删除，版本库文件删除

1. rm test.txt

2. git rm test.txt

3. git commit -m "remove test.txt"

以下命令可恢复文件（回到上一个版本）：

git reset --hard HEAD^

# 远程仓库
#### (1)从本地到远程仓库
（初始链接省略）代码：
> git push -u origin master(推送的是master分支)

删除远程库
1）查看远程库的信息
> git remote -v

2)根据名字进行删除
> git remote rm 文件名

**注意：** 这里的删除指的是接触本地与远程的绑定关系，并不是物理的删除，要真正删除则要在Github上删除

#### （2）从远程仓库到本地
（在github上创建仓库省略）代码：
> git clone git@github:用户名/仓库名.git

然后进行查看
>cd 文件名
ls

# 分支
#### （1）创建一个分支(以dev为名字)
> git branch dev
git checkout dev

第一条为创建分支，第二条为切换到该分支，也可以浓缩为下面一条：
>git checkout -b dev

#### (2)查看分支
> git branch

会显示全部分支，其中带*的为当前分支

####（3）合并分支
若要合并dev分支与主分支，则先切换回主分支
> git checkout master

合并
> git merge dev

这个命令是合并dev分支到当前分支，也就是切换后的主分支

##### （4）删除分支
> git branch -d dev

#### (5)切换分支（switch方法）
创建并切换到新的分支
> git switch -c dev

直接切换到已有的分支master
> git switch master