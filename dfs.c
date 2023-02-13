
//图论算法
/*
    图的分类：
        1.有向图
        2.无向图
        3.权重图
            a.权重有向图
            b.权重无向图
    图的基本概念：
        1.顶点集合(vex-set)：如S(vex) = {'A','B','C','D','E','F'}
        2.边集合(arc-set)：如S(arc) = {<'A','B'>,<'A','C'>,<'A','D'>,
        <'B','F'>,<'B','C'>,<'C','E'>,<'D','E'>,<'E','F'>}
        3.度(degree)：无向图中从一个点延伸出去的边数就是该点的度；有向图
        中包含出度和入度
        4.出度(out-degree)：有多少条边指向某点就是该点的出度
        5.入度(in-degree)：从某点出发向外指向延伸的边数就是该点的入度
    图的存储：
        1.存储的关键是点集合和边集合
        2.邻接矩阵：顶点信息存储在一维数组中，边信息存储在二维数组中
        vex[6] = {'A', 'B', 'C', 'D', 'E, 'F'}
        arc[6][6] = {
            0, 1, 1, 1, 0, 0,
            1, 0, 1, 0, 0, 1,
            1, 1, 0, 0, 1, 0,
            1, 0, 0, 0, 1, 0,
            0, 0, 1, 1, 0, 1,
            0, 1, 0, 0, 1, 0,
        }
        优点：很容易算出边邻接关系，以及节点的度(不管出度还是入度)
        缺点：边集合存储空间复杂度大，图中大量0，空间利用率不高，（尤其是点
        多边少的情况下）；对于无向图，邻接矩阵是对阵的，可以只存下半部分
        3.链接表：顶点集合依然存储在一维数组当中，边集合存储在连接表当中
            有向图：
            A->B->C->D
            B->F
            C->B->E
            D->E
            E->F
            F
            无向图：
            A->B->C->D
            B->A->C->F
            C->A->B->E
            D->A->E
            E->C->D->F
            F->B->E
            权重无向图：
            A->12,B->1,C->6,D
            B->12,A->13,C->5,F
            C->1,A->13,B->3E
            D->6,A->9,E
            E->3,C->9,D->15,F
            F->5,B->15,E
            优点：很容易算出邻接关系，以及节点的出度
            缺点：很难算出入度，需要遍历整张表，可以同时建立一张逆连接表(相当于
            记录入度的表)
            A
            B->A->C
            C->A
            D->A
            E->C->D
            F->B->E
    图的遍历：
        1.从图中的某一个顶点出发，访问图中其余顶点，使每个顶点被访问一次且只被访问一次
        2.可以从图中任意一个顶点出发进行遍历
        3.需要解决的问题：
            a.确定一条搜索路径
            b.确保每个顶点都被访问到
            c.确保每个顶点只能被访问一次
        4.设置辅助数组visited，数组元素的初始值均为false,一旦遍历过就置为true
    深度优先搜索(dfs)：
        1.应用：
            a.检测连通分量的个数
            b.两个点是否在一个连通分量中
            c.检测是否构成环，从一个点出发能否回到出发点
    广度优先搜索：(bfs)
        1.关键数据结构：队列
        2.应用：
            a.游戏中找寻路径问题
    迪杰斯特拉算法：
        1.该算法主要解决最短路径问题，采用贪心思想
        2.对象：权重图
        3.该算法思想是，每次从路径最短的点出发遍历相邻边，检测修改路径值（确保相邻点也是最短），
        从未被确认路径最短的顶点集合中选择最短路径的点，将该点加入确认路径最短的顶点集合，并将
        该点作为下次遍历相邻边的出发点
        4.核心步骤：更新，扫描，修改
*/

//dsf(深度寻路算法)

#define MAXN 256

//G为已知图，n为起始顶点，a为顶点数，visited数组用于标记
void array_graph_dfs(array_graph *G, int n, int a, bool visited[]) {
    int i;
    //先访问起始顶点，再访问其他顶点
    printf("%c\t", G->vertex[n]);
    //标记起始顶点为true
    visited[n] = true;

    for (i = 0; i < a; ++i) {
        if (G->arcs[n][i] != 0 && visited[i] == 0) {
            array_graph_dfs(G, i, a, visited);
        }
    }

    for (i = 0; i < a; ++i) {
        if (visited[i] == 0) {
            array_graph_dfs(G, i, a, visited);
        }
    }
}

//递归
void dfs(array_graph *G, int n, int a) {
    bool visited[MAXN];
    int i;

    //对visited数组进行初始化，false表示为访问过，true表示访问过
    for (i = 0; i < a; ++i) {
        visited[i] = false;
    }

    array_graph_dfs(G,  n, a, visited);
}

//非递归
void dfs(graph *G, int v0) {
    int i, j;
    int flag = 0;
    int x;
    int visited[MAXN]; //标记顶点访问信息
    stack<int> Stack; //使用栈来实现

    for (i = 0; i < MAXN; ++i) {
        visited[i] = 0;
    }

    visited[v0] = 1;
    Stack.push(v0);

    while (!flag) {
        while (!Stack.empty()) {
            x = Stack.top();
            printf("%c", G->vextex[x]);

            for (i = MAXN - 1; i >= 0; --i) {
                if (visited[i] == 0 && G->arcs[x][i] != 0) {
                    Stack.push(i);
                    visited[i] = 1;
                }
            }
        }

        flag = 1;
        if (i = 0; i < MAXN; ++i) {
            if (visited[i] == 0) {
                flag = 0;
                vo = i;
                break;
            }
        }
    }
}