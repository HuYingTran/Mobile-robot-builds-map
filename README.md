# Mobile-robot-builds-map

Mô hình robot xây dựng bản đồ sử dụng thiết bị cảm biến khoảng cách và encoder ( dựa trên phương thức hoạt động tương tự lidar)

Xử lý tín hiệu nhiễu của cảm biến laser bằng Low Pass Filter .Mục đích loại bỏ các tín hiệu nhiễu có tần số cao từ môi trường

![image](https://user-images.githubusercontent.com/105936733/234927381-2dd47196-92ea-41ef-9da5-5cff20760e89.png)

Dùng bộ lọc Kalman Filter cho xung tín hiệu của Encoder

![image](https://user-images.githubusercontent.com/105936733/234928237-29c24497-0bbf-4fca-8d64-0df6ec66a570.png)

Công thức chuyển đổi thông số các senser thành vị trí vật cản

![image](https://user-images.githubusercontent.com/105936733/234929565-7620aa35-8af7-4d10-a60b-ca2e82373bf5.png)

Kết quả bản đồ thu được

![image](https://user-images.githubusercontent.com/105936733/234928553-8f09d696-2a2b-4154-a66c-1c8e3e301907.png)
![image](https://user-images.githubusercontent.com/105936733/234928689-f432e9ef-a429-48c0-aa6f-15df09f6c053.png)
