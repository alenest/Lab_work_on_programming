namespace GeographicalEntities
{
    partial class MainForm
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемые ресурсы должны быть освобождены; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.txtCityName = new System.Windows.Forms.TextBox();
            this.txtCityPopulation = new System.Windows.Forms.TextBox();
            this.btnCreateCity = new System.Windows.Forms.Button();
            this.btnShowInfo = new System.Windows.Forms.Button();
            this.txtRegionName = new System.Windows.Forms.TextBox();
            this.txtRegionNumber = new System.Windows.Forms.TextBox();
            this.btnCreateRegion = new System.Windows.Forms.Button();
            this.txtMegapolisName = new System.Windows.Forms.TextBox();
            this.txtMegapolisPopulation = new System.Windows.Forms.TextBox();
            this.txtMegapolisRegionName = new System.Windows.Forms.TextBox();
            this.txtMegapolisRegionNumber = new System.Windows.Forms.TextBox();
            this.txtMegapolisArea = new System.Windows.Forms.TextBox();
            this.btnCreateMegapolis = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // txtCityName
            // 
            this.txtCityName.Location = new System.Drawing.Point(40, 37);
            this.txtCityName.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.txtCityName.Name = "txtCityName";
            this.txtCityName.Size = new System.Drawing.Size(132, 22);
            this.txtCityName.TabIndex = 0;
            // 
            // txtCityPopulation
            // 
            this.txtCityPopulation.Location = new System.Drawing.Point(40, 74);
            this.txtCityPopulation.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.txtCityPopulation.Name = "txtCityPopulation";
            this.txtCityPopulation.Size = new System.Drawing.Size(132, 22);
            this.txtCityPopulation.TabIndex = 1;
            // 
            // btnCreateCity
            // 
            this.btnCreateCity.Location = new System.Drawing.Point(40, 111);
            this.btnCreateCity.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.btnCreateCity.Name = "btnCreateCity";
            this.btnCreateCity.Size = new System.Drawing.Size(133, 28);
            this.btnCreateCity.TabIndex = 2;
            this.btnCreateCity.Text = "Создать город";
            this.btnCreateCity.UseVisualStyleBackColor = true;
            this.btnCreateCity.Click += new System.EventHandler(this.btnCreateCity_Click);
            // 
            // btnShowInfo
            // 
            this.btnShowInfo.Location = new System.Drawing.Point(40, 267);
            this.btnShowInfo.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.btnShowInfo.Name = "btnShowInfo";
            this.btnShowInfo.Size = new System.Drawing.Size(452, 28);
            this.btnShowInfo.TabIndex = 3;
            this.btnShowInfo.Text = "Показать информацию";
            this.btnShowInfo.UseVisualStyleBackColor = true;
            this.btnShowInfo.Click += new System.EventHandler(this.btnShowInfo_Click);
            // 
            // txtRegionName
            // 
            this.txtRegionName.Location = new System.Drawing.Point(200, 37);
            this.txtRegionName.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.txtRegionName.Name = "txtRegionName";
            this.txtRegionName.Size = new System.Drawing.Size(132, 22);
            this.txtRegionName.TabIndex = 4;
            // 
            // txtRegionNumber
            // 
            this.txtRegionNumber.Location = new System.Drawing.Point(200, 74);
            this.txtRegionNumber.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.txtRegionNumber.Name = "txtRegionNumber";
            this.txtRegionNumber.Size = new System.Drawing.Size(132, 22);
            this.txtRegionNumber.TabIndex = 5;
            // 
            // btnCreateRegion
            // 
            this.btnCreateRegion.Location = new System.Drawing.Point(200, 111);
            this.btnCreateRegion.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.btnCreateRegion.Name = "btnCreateRegion";
            this.btnCreateRegion.Size = new System.Drawing.Size(133, 28);
            this.btnCreateRegion.TabIndex = 6;
            this.btnCreateRegion.Text = "Создать регион";
            this.btnCreateRegion.UseVisualStyleBackColor = true;
            this.btnCreateRegion.Click += new System.EventHandler(this.btnCreateRegion_Click);
            // 
            // txtMegapolisName
            // 
            this.txtMegapolisName.Location = new System.Drawing.Point(360, 37);
            this.txtMegapolisName.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.txtMegapolisName.Name = "txtMegapolisName";
            this.txtMegapolisName.Size = new System.Drawing.Size(132, 22);
            this.txtMegapolisName.TabIndex = 7;
            // 
            // txtMegapolisPopulation
            // 
            this.txtMegapolisPopulation.Location = new System.Drawing.Point(360, 74);
            this.txtMegapolisPopulation.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.txtMegapolisPopulation.Name = "txtMegapolisPopulation";
            this.txtMegapolisPopulation.Size = new System.Drawing.Size(132, 22);
            this.txtMegapolisPopulation.TabIndex = 8;
            // 
            // txtMegapolisRegionName
            // 
            this.txtMegapolisRegionName.Location = new System.Drawing.Point(360, 111);
            this.txtMegapolisRegionName.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.txtMegapolisRegionName.Name = "txtMegapolisRegionName";
            this.txtMegapolisRegionName.Size = new System.Drawing.Size(132, 22);
            this.txtMegapolisRegionName.TabIndex = 9;
            // 
            // txtMegapolisRegionNumber
            // 
            this.txtMegapolisRegionNumber.Location = new System.Drawing.Point(360, 148);
            this.txtMegapolisRegionNumber.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.txtMegapolisRegionNumber.Name = "txtMegapolisRegionNumber";
            this.txtMegapolisRegionNumber.Size = new System.Drawing.Size(132, 22);
            this.txtMegapolisRegionNumber.TabIndex = 10;
            // 
            // txtMegapolisArea
            // 
            this.txtMegapolisArea.Location = new System.Drawing.Point(360, 185);
            this.txtMegapolisArea.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.txtMegapolisArea.Name = "txtMegapolisArea";
            this.txtMegapolisArea.Size = new System.Drawing.Size(132, 22);
            this.txtMegapolisArea.TabIndex = 11;
            // 
            // btnCreateMegapolis
            // 
            this.btnCreateMegapolis.Location = new System.Drawing.Point(360, 222);
            this.btnCreateMegapolis.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.btnCreateMegapolis.Name = "btnCreateMegapolis";
            this.btnCreateMegapolis.Size = new System.Drawing.Size(133, 28);
            this.btnCreateMegapolis.TabIndex = 12;
            this.btnCreateMegapolis.Text = "Создать мегаполис";
            this.btnCreateMegapolis.UseVisualStyleBackColor = true;
            this.btnCreateMegapolis.Click += new System.EventHandler(this.btnCreateMegapolis_Click);
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(533, 308);
            this.Controls.Add(this.btnCreateMegapolis);
            this.Controls.Add(this.txtMegapolisArea);
            this.Controls.Add(this.txtMegapolisRegionNumber);
            this.Controls.Add(this.txtMegapolisRegionName);
            this.Controls.Add(this.txtMegapolisPopulation);
            this.Controls.Add(this.txtMegapolisName);
            this.Controls.Add(this.btnCreateRegion);
            this.Controls.Add(this.txtRegionNumber);
            this.Controls.Add(this.txtRegionName);
            this.Controls.Add(this.btnShowInfo);
            this.Controls.Add(this.btnCreateCity);
            this.Controls.Add(this.txtCityPopulation);
            this.Controls.Add(this.txtCityName);
            this.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.Name = "MainForm";
            this.Text = "Географические объекты";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox txtCityName;
        private System.Windows.Forms.TextBox txtCityPopulation;
        private System.Windows.Forms.Button btnCreateCity;
        private System.Windows.Forms.Button btnShowInfo;
        private System.Windows.Forms.TextBox txtRegionName;
        private System.Windows.Forms.TextBox txtRegionNumber;
        private System.Windows.Forms.Button btnCreateRegion;
        private System.Windows.Forms.TextBox txtMegapolisName;
        private System.Windows.Forms.TextBox txtMegapolisPopulation;
        private System.Windows.Forms.TextBox txtMegapolisRegionName;
        private System.Windows.Forms.TextBox txtMegapolisRegionNumber;
        private System.Windows.Forms.TextBox txtMegapolisArea;
        private System.Windows.Forms.Button btnCreateMegapolis;
    }
}

//namespace GeographicalEntities
//{
//    partial class MainForm
//    {
//        /// <summary>
//        /// Обязательная переменная конструктора.
//        /// </summary>
//        private System.ComponentModel.IContainer components = null;

//        /// <summary>
//        /// Освободить все используемые ресурсы.
//        /// </summary>
//        /// <param name="disposing">истинно, если управляемые ресурсы должны быть освобождены; иначе ложно.</param>
//        protected override void Dispose(bool disposing)
//        {
//            if (disposing && (components != null))
//            {
//                components.Dispose();
//            }
//            base.Dispose(disposing);
//        }

//        #region Код, автоматически созданный конструктором форм

//        /// <summary>
//        /// Требуемый метод для поддержки конструктора — не изменяйте
//        /// содержимое этого метода с помощью редактора кода.
//        /// </summary>
//        private void InitializeComponent()
//        {
//            this.txtCityName = new System.Windows.Forms.TextBox();
//            this.txtCityPopulation = new System.Windows.Forms.TextBox();
//            this.btnCreateCity = new System.Windows.Forms.Button();
//            this.btnShowInfo = new System.Windows.Forms.Button();
//            this.txtRegionName = new System.Windows.Forms.TextBox();
//            this.txtRegionNumber = new System.Windows.Forms.TextBox();
//            this.btnCreateRegion = new System.Windows.Forms.Button();
//            this.txtMegapolisName = new System.Windows.Forms.TextBox();
//            this.txtMegapolisPopulation = new System.Windows.Forms.TextBox();
//            this.txtMegapolisRegionName = new System.Windows.Forms.TextBox();
//            this.txtMegapolisRegionNumber = new System.Windows.Forms.TextBox();
//            this.txtMegapolisArea = new System.Windows.Forms.TextBox();
//            this.btnCreateMegapolis = new System.Windows.Forms.Button();
//            this.SuspendLayout();
//            // 
//            // txtCityName
//            // 
//            this.txtCityName.Location = new System.Drawing.Point(30, 30);
//            this.txtCityName.Name = "txtCityName";
//            this.txtCityName.Size = new System.Drawing.Size(100, 20);
//            this.txtCityName.TabIndex = 0;
//            this.txtCityName.PlaceholderText = "Название города";
//            // 
//            // txtCityPopulation
//            // 
//            this.txtCityPopulation.Location = new System.Drawing.Point(30, 60);
//            this.txtCityPopulation.Name = "txtCityPopulation";
//            this.txtCityPopulation.Size = new System.Drawing.Size(100, 20);
//            this.txtCityPopulation.TabIndex = 1;
//            this.txtCityPopulation.PlaceholderText = "Население города";
//            // 
//            // btnCreateCity
//            // 
//            this.btnCreateCity.Location = new System.Drawing.Point(30, 90);
//            this.btnCreateCity.Name = "btnCreateCity";
//            this.btnCreateCity.Size = new System.Drawing.Size(100, 23);
//            this.btnCreateCity.TabIndex = 2;
//            this.btnCreateCity.Text = "Создать город";
//            this.btnCreateCity.UseVisualStyleBackColor = true;
//            this.btnCreateCity.Click += new System.EventHandler(this.btnCreateCity_Click);
//            // 
//            // btnShowInfo
//            // 
//            this.btnShowInfo.Location = new System.Drawing.Point(30, 120);
//            this.btnShowInfo.Name = "btnShowInfo";
//            this.btnShowInfo.Size = new System.Drawing.Size(100, 23);
//            this.btnShowInfo.TabIndex = 3;
//            this.btnShowInfo.Text = "Показать информацию";
//            this.btnShowInfo.UseVisualStyleBackColor = true;
//            this.btnShowInfo.Click += new System.EventHandler(this.btnShowInfo_Click);
//            // 
//            // txtRegionName
//            // 
//            this.txtRegionName.Location = new System.Drawing.Point(150, 30);
//            this.txtRegionName.Name = "txtRegionName";
//            this.txtRegionName.Size = new System.Drawing.Size(100, 20);
//            this.txtRegionName.TabIndex = 4;
//            this.txtRegionName.PlaceholderText = "Название региона";
//            // 
//            // txtRegionNumber
//            // 
//            this.txtRegionNumber.Location = new System.Drawing.Point(150, 60);
//            this.txtRegionNumber.Name = "txtRegionNumber";
//            this.txtRegionNumber.Size = new System.Drawing.Size(100, 20);
//            this.txtRegionNumber.TabIndex = 5;
//            this.txtRegionNumber.PlaceholderText = "Номер региона";
//            // 
//            // btnCreateRegion
//            // 
//            this.btnCreateRegion.Location = new System.Drawing.Point(150, 90);
//            this.btnCreateRegion.Name = "btnCreateRegion";
//            this.btnCreateRegion.Size = new System.Drawing.Size(100, 23);
//            this.btnCreateRegion.TabIndex = 6;
//            this.btnCreateRegion.Text = "Создать регион";
//            this.btnCreateRegion.UseVisualStyleBackColor = true;
//            this.btnCreateRegion.Click += new System.EventHandler(this.btnCreateRegion_Click);
//            // 
//            // txtMegapolisName
//            // 
//            this.txtMegapolisName.Location = new System.Drawing.Point(270, 30);
//            this.txtMegapolisName.Name = "txtMegapolisName";
//            this.txtMegapolisName.Size = new System.Drawing.Size(100, 20);
//            this.txtMegapolisName.TabIndex = 7;
//            this.txtMegapolisName.PlaceholderText = "Название мегаполиса";
//            // 
//            // txtMegapolisPopulation
//            // 
//            this.txtMegapolisPopulation.Location = new System.Drawing.Point(270, 60);
//            this.txtMegapolisPopulation.Name = "txtMegapolisPopulation";
//            this.txtMegapolisPopulation.Size = new System.Drawing.Size(100, 20);
//            this.txtMegapolisPopulation.TabIndex = 8;
//            this.txtMegapolisPopulation.PlaceholderText = "Население мегаполиса";
//            // 
//            // txtMegapolisRegionName
//            // 
//            this.txtMegapolisRegionName.Location = new System.Drawing.Point(270, 90);
//            this.txtMegapolisRegionName.Name = "txtMegapolisRegionName";
//            this.txtMegapolisRegionName.Size = new System.Drawing.Size(100, 20);
//            this.txtMegapolisRegionName.TabIndex = 9;
//            this.txtMegapolisRegionName.PlaceholderText = "Название региона мегаполиса";
//            // 
//            // txtMegapolisRegionNumber
//            // 
//            this.txtMegapolisRegionNumber.Location = new System.Drawing.Point(270, 120);
//            this.txtMegapolisRegionNumber.Name = "txtMegapolisRegionNumber";
//            this.txtMegapolisRegionNumber.Size = new System.Drawing.Size(100, 20);
//            this.txtMegapolisRegionNumber.TabIndex = 10;
//            this.txtMegapolisRegionNumber.PlaceholderText = "Номер региона мегаполиса";
//            // 
//            // txtMegapolisArea
//            // 
//            this.txtMegapolisArea.Location = new System.Drawing.Point(270, 150);
//            this.txtMegapolisArea.Name = "txtMegapolisArea";
//            this.txtMegapolisArea.Size = new System.Drawing.Size(100, 20);
//            this.txtMegapolisArea.TabIndex = 11;
//            this.txtMegapolisArea.PlaceholderText = "Площадь мегаполиса";
//            // 
//            // btnCreateMegapolis
//            // 
//            this.btnCreateMegapolis.Location = new System.Drawing.Point(270, 180);
//            this.btnCreateMegapolis.Name = "btnCreateMegapolis";
//            this.btnCreateMegapolis.Size = new System.Drawing.Size(100, 23);
//            this.btnCreateMegapolis.TabIndex = 12;
//            this.btnCreateMegapolis.Text = "Создать мегаполис";
//            this.btnCreateMegapolis.UseVisualStyleBackColor = true;
//            this.btnCreateMegapolis.Click += new System.EventHandler(this.btnCreateMegapolis_Click);
//            // 
//            // MainForm
//            // 
//            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
//            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
//            this.ClientSize = new System.Drawing.Size(400, 250);
//            this.Controls.Add(this.btnCreateMegapolis);
//            this.Controls.Add(this.txtMegapolisArea);
//            this.Controls.Add(this.txtMegapolisRegionNumber);
//            this.Controls.Add(this.txtMegapolisRegionName);
//            this.Controls.Add(this.txtMegapolisPopulation);
//            this.Controls.Add(this.txtMegapolisName);
//            this.Controls.Add(this.btnCreateRegion);
//            this.Controls.Add(this.txtRegionNumber);
//            this.Controls.Add(this.txtRegionName);
//            this.Controls.Add(this.btnShowInfo);
//            this.Controls.Add(this.btnCreateCity);
//            this.Controls.Add(this.txtCityPopulation);
//            this.Controls.Add(this.txtCityName);
//            this.Name = "MainForm";
//            this.Text = "Географические объекты";
//            this.ResumeLayout(false);
//            this.PerformLayout();
//        }

//        #endregion

//        private System.Windows.Forms.TextBox txtCityName;
//        private System.Windows.Forms.TextBox txtCityPopulation;
//        private System.Windows.Forms.Button btnCreateCity;
//        private System.Windows.Forms.Button btnShowInfo;
//        private System.Windows.Forms.TextBox txtRegionName;
//        private System.Windows.Forms.TextBox txtRegionNumber;
//        private System.Windows.Forms.Button btnCreateRegion;
//        private System.Windows.Forms.TextBox txtMegapolisName;
//        private System.Windows.Forms.TextBox txtMegapolisPopulation;
//        private System.Windows.Forms.TextBox txtMegapolisRegionName;
//        private System.Windows.Forms.TextBox txtMegapolisRegionNumber;
//        private System.Windows.Forms.TextBox txtMegapolisArea;
//        private System.Windows.Forms.Button btnCreateMegapolis;
//    }
//}
