f = r"D:\pingye_pack\development\current\woldvein_trainer0.4.2\src\advanced_tools.py"
c = open(f, encoding="utf-8").read()
old = """    local boom = nil
    if g_camp and g_camp.boom then
        boom = g_camp.boom
    elseif g_CityManager and g_CityManager.m_lActiveCity then
        local city = g_CityManager.m_lActiveCity
        if city.boom then boom = city.boom end
    end
    if not boom then
        return "[失败] g_camp.boom 不存在（请先进入游戏场景）"
    end\""""
new = """    local boom = nil
    if g_camp and g_camp.boom then
        boom = g_camp.boom
    end
    if not boom then
        return "[失败] g_camp.boom 不存在（请先进入游戏场景）"
    end\""""
c = c.replace(old, new)
open(f, "w", encoding="utf-8").write(c)
import ast
ast.parse(open(f, encoding="utf-8").read())
print("OK")
