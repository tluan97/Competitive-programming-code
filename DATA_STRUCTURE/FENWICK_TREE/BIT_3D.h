
query(x1,y1,z1,x2,y2,z2)

return query(x2,y2,z2)-query(x1,y1,z1)
+query(x2,y1,z1)+query(x1,y2,z1)+query(x1,y1,z2)
-query(x1,y2,z2)-query(x2,y1,z2)-query(x2,y2,z1);
