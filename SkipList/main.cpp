#include <iostream>
#include <string>
#include "skiplist.h"

int main() {
    srand(42); 

    std::cout << "====================================================\n";
    std::cout << "🧱 场景一：第一任引擎大厦拔地而起（正常营业）\n";
    std::cout << "====================================================\n";
    
    SkipList<int, std::string> kv_store1(6);
    kv_store1.insert_element(1, "北京");
    kv_store1.insert_element(2, "上海");
    kv_store1.insert_element(3, "广州");

    std::cout << "📸 [打烊归档]: 手动触发 dump_file，把当前的 1, 2, 3 做成永久快照...\n";
    kv_store1.dump_file("snapshot.txt"); 

    std::cout << "\n⚡ [业务继续]: 打烊后，突发紧急业务，新塞入 4，并删除了 2 ...\n";
    kv_store1.insert_element(4, "深圳");
    kv_store1.delete_element(2); // 👈 注意：这两步操作没有触发 dump，只实时躺在 wal.log 里！

    std::cout << "\n📊 断电前夕第一任引擎的最终内存网格：\n";
    kv_store1.display_list(); // 内存里此时是 1, 3, 4

    std::cout << "\n💥 [天灾断电]: 服务器瞬间断电！内存里的 1, 3, 4 连同 kv_store1 瞬间蒸发...\n\n";


    std::cout << "====================================================\n";
    std::cout << "🏗️ 场景二：第二任引擎在废墟中冷启动（联合复活连招）\n";
    std::cout << "====================================================\n";
    
    SkipList<int, std::string> kv_store2(6);
    std::cout << "📊 新引擎初始内存状态：一片虚无，数据量 = " << kv_store2.size() << "\n\n";

    // 顺序 1：先加载大部队（快照）
    std::cout << "⏳ 连招第一式：调用 load_file 加载旧快照...\n";
    kv_store2.load_file("snapshot.txt"); 
    std::cout << "📊 此时内存数据（快照老账本）:\n";
    kv_store2.display_list(); // 这时候复活了 1, 2, 3，但缺少了断电前的最新变更 4，且错误的带着被删的 2

    // 顺序 2：再重放小碎步（WAL日志）
    std::cout << "\n⏳ 连招第二式：调用 replay_wal 重放断电前的残存日志...\n";
    kv_store2.replay_wal(); // 它会读到后面的“插入4”和“删除2”，对内存进行校准！

    std::cout << "\n====================================================\n";
    std::cout << "🏆 终极对账时刻：两手抓、两手都要硬的完美复活成果\n";
    std::cout << "====================================================\n";
    std::cout << "📊 经历【快照恢复】+【日志重放】双重洗礼后的最终内存网格：\n";
    kv_store2.display_list(); // 奇迹出现：完美的 1, 3, 4！和断电前像素级一模一样！

    return 0;
}