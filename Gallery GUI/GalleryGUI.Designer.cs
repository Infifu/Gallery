using System.Drawing;

namespace Gallery_GUI
{
    partial class GalleryGUI
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.SideBar = new System.Windows.Forms.Panel();
            this.GalleryLAbel = new System.Windows.Forms.Label();
            this.userENTRY = new System.Windows.Forms.TextBox();
            this.AcceptBTN = new System.Windows.Forms.Button();
            this.EntryPANEL = new System.Windows.Forms.Panel();
            this.UserName = new System.Windows.Forms.Label();
            this.DataShow = new System.Windows.Forms.Panel();
            this.Close = new System.Windows.Forms.Button();
            this.DataLabel = new System.Windows.Forms.Label();
            this.AlbumPanel = new System.Windows.Forms.Panel();
            this.albumEnter = new System.Windows.Forms.Button();
            this.albumtxt2 = new System.Windows.Forms.TextBox();
            this.albumtxt1 = new System.Windows.Forms.TextBox();
            this.AlbumEntry2 = new System.Windows.Forms.Label();
            this.AlbumEntry1 = new System.Windows.Forms.Label();
            this.currAlbumLabel = new System.Windows.Forms.Label();
            this.TagUserBTN = new System.Windows.Forms.Button();
            this.button6 = new System.Windows.Forms.Button();
            this.ListTagsBTN = new System.Windows.Forms.Button();
            this.imageListPanel = new System.Windows.Forms.Panel();
            this.TagPanel = new System.Windows.Forms.Panel();
            this.aceeptTAG = new System.Windows.Forms.Button();
            this.tagBox = new System.Windows.Forms.TextBox();
            this.taguserLabel = new System.Windows.Forms.Label();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.CloseImage = new System.Windows.Forms.Button();
            this.Next = new System.Windows.Forms.Button();
            this.Prev = new System.Windows.Forms.Button();
            this.tagListPanel = new System.Windows.Forms.Panel();
            this.tagListLabel = new System.Windows.Forms.Label();
            this.userMenu = new System.Windows.Forms.Button();
            this.userPanel = new System.Windows.Forms.Panel();
            this.ListOfUserBTN = new System.Windows.Forms.Button();
            this.RemoveUserBTN = new System.Windows.Forms.Button();
            this.CreateUserBTN = new System.Windows.Forms.Button();
            this.albumMenu = new System.Windows.Forms.Button();
            this.panelAlbum = new System.Windows.Forms.Panel();
            this.listuseralbumsBTN = new System.Windows.Forms.Button();
            this.listalbumsBTN = new System.Windows.Forms.Button();
            this.delete_albumBTN = new System.Windows.Forms.Button();
            this.closeAlbum = new System.Windows.Forms.Button();
            this.open_album = new System.Windows.Forms.Button();
            this.CreateALBUM = new System.Windows.Forms.Button();
            this.picMenu = new System.Windows.Forms.Button();
            this.picPanel = new System.Windows.Forms.Panel();
            this.listPictures = new System.Windows.Forms.Button();
            this.RemovePicBTN = new System.Windows.Forms.Button();
            this.addPicBTN = new System.Windows.Forms.Button();
            this.SideBar.SuspendLayout();
            this.EntryPANEL.SuspendLayout();
            this.DataShow.SuspendLayout();
            this.AlbumPanel.SuspendLayout();
            this.imageListPanel.SuspendLayout();
            this.TagPanel.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.tagListPanel.SuspendLayout();
            this.userPanel.SuspendLayout();
            this.panelAlbum.SuspendLayout();
            this.picPanel.SuspendLayout();
            this.SuspendLayout();
            // 
            // SideBar
            // 
            this.SideBar.AutoScroll = true;
            this.SideBar.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(32)))), ((int)(((byte)(33)))), ((int)(((byte)(35)))));
            this.SideBar.Controls.Add(this.picPanel);
            this.SideBar.Controls.Add(this.picMenu);
            this.SideBar.Controls.Add(this.panelAlbum);
            this.SideBar.Controls.Add(this.albumMenu);
            this.SideBar.Controls.Add(this.userPanel);
            this.SideBar.Controls.Add(this.userMenu);
            this.SideBar.Controls.Add(this.GalleryLAbel);
            this.SideBar.ImeMode = System.Windows.Forms.ImeMode.Off;
            this.SideBar.Location = new System.Drawing.Point(0, -1);
            this.SideBar.Name = "SideBar";
            this.SideBar.Size = new System.Drawing.Size(239, 655);
            this.SideBar.TabIndex = 0;
            // 
            // GalleryLAbel
            // 
            this.GalleryLAbel.AutoSize = true;
            this.GalleryLAbel.Font = new System.Drawing.Font("Miriam", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.GalleryLAbel.ForeColor = System.Drawing.SystemColors.ActiveCaption;
            this.GalleryLAbel.Location = new System.Drawing.Point(12, 8);
            this.GalleryLAbel.Name = "GalleryLAbel";
            this.GalleryLAbel.Size = new System.Drawing.Size(136, 24);
            this.GalleryLAbel.TabIndex = 14;
            this.GalleryLAbel.Text = "Gallery GUI";
            // 
            // userENTRY
            // 
            this.userENTRY.Font = new System.Drawing.Font("Miriam", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.userENTRY.Location = new System.Drawing.Point(81, 64);
            this.userENTRY.Multiline = true;
            this.userENTRY.Name = "userENTRY";
            this.userENTRY.Size = new System.Drawing.Size(267, 32);
            this.userENTRY.TabIndex = 1;
            // 
            // AcceptBTN
            // 
            this.AcceptBTN.Font = new System.Drawing.Font("Miriam", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.AcceptBTN.Location = new System.Drawing.Point(301, 111);
            this.AcceptBTN.Name = "AcceptBTN";
            this.AcceptBTN.Size = new System.Drawing.Size(106, 44);
            this.AcceptBTN.TabIndex = 2;
            this.AcceptBTN.Text = "Accept";
            this.AcceptBTN.UseVisualStyleBackColor = true;
            this.AcceptBTN.MouseClick += new System.Windows.Forms.MouseEventHandler(this.AcceptBTN_MouseClick);
            // 
            // EntryPANEL
            // 
            this.EntryPANEL.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(55)))), ((int)(((byte)(55)))), ((int)(((byte)(65)))));
            this.EntryPANEL.Controls.Add(this.UserName);
            this.EntryPANEL.Controls.Add(this.AcceptBTN);
            this.EntryPANEL.Controls.Add(this.userENTRY);
            this.EntryPANEL.Location = new System.Drawing.Point(450, 237);
            this.EntryPANEL.Name = "EntryPANEL";
            this.EntryPANEL.Size = new System.Drawing.Size(416, 167);
            this.EntryPANEL.TabIndex = 3;
            this.EntryPANEL.Visible = false;
            // 
            // UserName
            // 
            this.UserName.AutoSize = true;
            this.UserName.Font = new System.Drawing.Font("Miriam", 21.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.UserName.ForeColor = System.Drawing.SystemColors.Control;
            this.UserName.Location = new System.Drawing.Point(3, 16);
            this.UserName.Name = "UserName";
            this.UserName.Size = new System.Drawing.Size(291, 29);
            this.UserName.TabIndex = 2;
            this.UserName.Text = "Enter your username:";
            this.UserName.Click += new System.EventHandler(this.label1_Click);
            // 
            // DataShow
            // 
            this.DataShow.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(55)))), ((int)(((byte)(55)))), ((int)(((byte)(65)))));
            this.DataShow.Controls.Add(this.Close);
            this.DataShow.Controls.Add(this.DataLabel);
            this.DataShow.Location = new System.Drawing.Point(443, 104);
            this.DataShow.Name = "DataShow";
            this.DataShow.Size = new System.Drawing.Size(423, 459);
            this.DataShow.TabIndex = 4;
            this.DataShow.Visible = false;
            // 
            // Close
            // 
            this.Close.BackColor = System.Drawing.Color.Gray;
            this.Close.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.Close.Font = new System.Drawing.Font("Miriam", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Close.Location = new System.Drawing.Point(153, 397);
            this.Close.Name = "Close";
            this.Close.Size = new System.Drawing.Size(124, 30);
            this.Close.TabIndex = 3;
            this.Close.Text = "Close";
            this.Close.UseVisualStyleBackColor = false;
            this.Close.Click += new System.EventHandler(this.Close_Click);
            // 
            // DataLabel
            // 
            this.DataLabel.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(55)))), ((int)(((byte)(55)))), ((int)(((byte)(65)))));
            this.DataLabel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.DataLabel.Font = new System.Drawing.Font("Miriam", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.DataLabel.ForeColor = System.Drawing.SystemColors.Control;
            this.DataLabel.Location = new System.Drawing.Point(0, 0);
            this.DataLabel.Name = "DataLabel";
            this.DataLabel.Size = new System.Drawing.Size(423, 459);
            this.DataLabel.TabIndex = 0;
            this.DataLabel.Text = "Awaiting";
            this.DataLabel.Click += new System.EventHandler(this.DataLabel_Click);
            // 
            // AlbumPanel
            // 
            this.AlbumPanel.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(55)))), ((int)(((byte)(55)))), ((int)(((byte)(65)))));
            this.AlbumPanel.Controls.Add(this.albumEnter);
            this.AlbumPanel.Controls.Add(this.albumtxt2);
            this.AlbumPanel.Controls.Add(this.albumtxt1);
            this.AlbumPanel.Controls.Add(this.AlbumEntry2);
            this.AlbumPanel.Controls.Add(this.AlbumEntry1);
            this.AlbumPanel.Location = new System.Drawing.Point(446, 104);
            this.AlbumPanel.Name = "AlbumPanel";
            this.AlbumPanel.Size = new System.Drawing.Size(423, 459);
            this.AlbumPanel.TabIndex = 4;
            this.AlbumPanel.Visible = false;
            // 
            // albumEnter
            // 
            this.albumEnter.Font = new System.Drawing.Font("Miriam", 20.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.albumEnter.Location = new System.Drawing.Point(291, 383);
            this.albumEnter.Name = "albumEnter";
            this.albumEnter.Size = new System.Drawing.Size(108, 56);
            this.albumEnter.TabIndex = 4;
            this.albumEnter.Text = "Enter";
            this.albumEnter.UseVisualStyleBackColor = true;
            this.albumEnter.Click += new System.EventHandler(this.albumEnter_Click);
            // 
            // albumtxt2
            // 
            this.albumtxt2.Font = new System.Drawing.Font("Miriam", 18F, System.Drawing.FontStyle.Bold);
            this.albumtxt2.Location = new System.Drawing.Point(20, 235);
            this.albumtxt2.Multiline = true;
            this.albumtxt2.Name = "albumtxt2";
            this.albumtxt2.Size = new System.Drawing.Size(379, 44);
            this.albumtxt2.TabIndex = 3;
            // 
            // albumtxt1
            // 
            this.albumtxt1.Font = new System.Drawing.Font("Miriam", 18F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.albumtxt1.Location = new System.Drawing.Point(20, 67);
            this.albumtxt1.Multiline = true;
            this.albumtxt1.Name = "albumtxt1";
            this.albumtxt1.Size = new System.Drawing.Size(379, 44);
            this.albumtxt1.TabIndex = 2;
            // 
            // AlbumEntry2
            // 
            this.AlbumEntry2.AutoSize = true;
            this.AlbumEntry2.Font = new System.Drawing.Font("Miriam", 20.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.AlbumEntry2.ForeColor = System.Drawing.SystemColors.Control;
            this.AlbumEntry2.Location = new System.Drawing.Point(15, 178);
            this.AlbumEntry2.Name = "AlbumEntry2";
            this.AlbumEntry2.Size = new System.Drawing.Size(240, 27);
            this.AlbumEntry2.TabIndex = 1;
            this.AlbumEntry2.Text = "Enter album name:";
            // 
            // AlbumEntry1
            // 
            this.AlbumEntry1.AutoSize = true;
            this.AlbumEntry1.Font = new System.Drawing.Font("Miriam", 20.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.AlbumEntry1.ForeColor = System.Drawing.SystemColors.Control;
            this.AlbumEntry1.Location = new System.Drawing.Point(15, 16);
            this.AlbumEntry1.Name = "AlbumEntry1";
            this.AlbumEntry1.Size = new System.Drawing.Size(181, 27);
            this.AlbumEntry1.TabIndex = 0;
            this.AlbumEntry1.Text = "Enter user ID:";
            // 
            // currAlbumLabel
            // 
            this.currAlbumLabel.AutoSize = true;
            this.currAlbumLabel.Font = new System.Drawing.Font("Miriam", 24F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.currAlbumLabel.ForeColor = System.Drawing.SystemColors.Control;
            this.currAlbumLabel.Location = new System.Drawing.Point(502, 9);
            this.currAlbumLabel.Name = "currAlbumLabel";
            this.currAlbumLabel.Size = new System.Drawing.Size(307, 32);
            this.currAlbumLabel.TabIndex = 5;
            this.currAlbumLabel.Text = "Current Album: None";
            // 
            // TagUserBTN
            // 
            this.TagUserBTN.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(240)))), ((int)(((byte)(236)))), ((int)(((byte)(236)))));
            this.TagUserBTN.Font = new System.Drawing.Font("Miriam", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.TagUserBTN.Location = new System.Drawing.Point(7, 465);
            this.TagUserBTN.Name = "TagUserBTN";
            this.TagUserBTN.Size = new System.Drawing.Size(124, 30);
            this.TagUserBTN.TabIndex = 17;
            this.TagUserBTN.Text = "Tag users";
            this.TagUserBTN.UseVisualStyleBackColor = false;
            this.TagUserBTN.Click += new System.EventHandler(this.TagUserBTN_Click);
            // 
            // button6
            // 
            this.button6.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(240)))), ((int)(((byte)(236)))), ((int)(((byte)(236)))));
            this.button6.Font = new System.Drawing.Font("Miriam", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button6.Location = new System.Drawing.Point(153, 465);
            this.button6.Name = "button6";
            this.button6.Size = new System.Drawing.Size(124, 30);
            this.button6.TabIndex = 18;
            this.button6.Text = "Untag users";
            this.button6.UseVisualStyleBackColor = false;
            this.button6.Click += new System.EventHandler(this.button6_Click);
            // 
            // ListTagsBTN
            // 
            this.ListTagsBTN.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(240)))), ((int)(((byte)(236)))), ((int)(((byte)(236)))));
            this.ListTagsBTN.Font = new System.Drawing.Font("Miriam", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ListTagsBTN.Location = new System.Drawing.Point(294, 465);
            this.ListTagsBTN.Name = "ListTagsBTN";
            this.ListTagsBTN.Size = new System.Drawing.Size(124, 30);
            this.ListTagsBTN.TabIndex = 19;
            this.ListTagsBTN.Text = "List tags";
            this.ListTagsBTN.UseVisualStyleBackColor = false;
            this.ListTagsBTN.Click += new System.EventHandler(this.listTags_click);
            // 
            // imageListPanel
            // 
            this.imageListPanel.Controls.Add(this.TagPanel);
            this.imageListPanel.Controls.Add(this.pictureBox1);
            this.imageListPanel.Controls.Add(this.ListTagsBTN);
            this.imageListPanel.Controls.Add(this.CloseImage);
            this.imageListPanel.Controls.Add(this.button6);
            this.imageListPanel.Controls.Add(this.Next);
            this.imageListPanel.Controls.Add(this.TagUserBTN);
            this.imageListPanel.Controls.Add(this.Prev);
            this.imageListPanel.Location = new System.Drawing.Point(443, 104);
            this.imageListPanel.Name = "imageListPanel";
            this.imageListPanel.Size = new System.Drawing.Size(426, 516);
            this.imageListPanel.TabIndex = 6;
            this.imageListPanel.Visible = false;
            // 
            // TagPanel
            // 
            this.TagPanel.Controls.Add(this.aceeptTAG);
            this.TagPanel.Controls.Add(this.tagBox);
            this.TagPanel.Controls.Add(this.taguserLabel);
            this.TagPanel.Location = new System.Drawing.Point(0, 225);
            this.TagPanel.Name = "TagPanel";
            this.TagPanel.Size = new System.Drawing.Size(426, 100);
            this.TagPanel.TabIndex = 20;
            this.TagPanel.Visible = false;
            // 
            // aceeptTAG
            // 
            this.aceeptTAG.Font = new System.Drawing.Font("Miriam", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.aceeptTAG.Location = new System.Drawing.Point(325, 70);
            this.aceeptTAG.Name = "aceeptTAG";
            this.aceeptTAG.Size = new System.Drawing.Size(75, 23);
            this.aceeptTAG.TabIndex = 2;
            this.aceeptTAG.Text = "accept";
            this.aceeptTAG.UseVisualStyleBackColor = true;
            this.aceeptTAG.Click += new System.EventHandler(this.aceeptTAG_Click);
            // 
            // tagBox
            // 
            this.tagBox.Font = new System.Drawing.Font("Miriam", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.tagBox.Location = new System.Drawing.Point(118, 38);
            this.tagBox.Name = "tagBox";
            this.tagBox.Size = new System.Drawing.Size(296, 27);
            this.tagBox.TabIndex = 1;
            // 
            // taguserLabel
            // 
            this.taguserLabel.AutoSize = true;
            this.taguserLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.taguserLabel.ForeColor = System.Drawing.SystemColors.Control;
            this.taguserLabel.Location = new System.Drawing.Point(15, 10);
            this.taguserLabel.Name = "taguserLabel";
            this.taguserLabel.Size = new System.Drawing.Size(138, 24);
            this.taguserLabel.TabIndex = 0;
            this.taguserLabel.Text = "Enter user ID:";
            // 
            // pictureBox1
            // 
            this.pictureBox1.Location = new System.Drawing.Point(54, 16);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(312, 372);
            this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBox1.TabIndex = 21;
            this.pictureBox1.TabStop = false;
            // 
            // CloseImage
            // 
            this.CloseImage.BackColor = System.Drawing.Color.RosyBrown;
            this.CloseImage.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.CloseImage.Font = new System.Drawing.Font("Miriam", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.CloseImage.ForeColor = System.Drawing.SystemColors.ControlText;
            this.CloseImage.Location = new System.Drawing.Point(407, 0);
            this.CloseImage.Name = "CloseImage";
            this.CloseImage.Size = new System.Drawing.Size(19, 20);
            this.CloseImage.TabIndex = 3;
            this.CloseImage.Text = "X";
            this.CloseImage.UseVisualStyleBackColor = false;
            this.CloseImage.Click += new System.EventHandler(this.CloseImage_Click);
            // 
            // Next
            // 
            this.Next.Font = new System.Drawing.Font("Miriam", 12F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Next.Location = new System.Drawing.Point(308, 403);
            this.Next.Name = "Next";
            this.Next.Size = new System.Drawing.Size(88, 36);
            this.Next.TabIndex = 2;
            this.Next.Text = "Next";
            this.Next.UseVisualStyleBackColor = true;
            this.Next.Click += new System.EventHandler(this.Next_Click);
            // 
            // Prev
            // 
            this.Prev.Font = new System.Drawing.Font("Miriam", 12F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))));
            this.Prev.Location = new System.Drawing.Point(23, 403);
            this.Prev.Name = "Prev";
            this.Prev.Size = new System.Drawing.Size(92, 36);
            this.Prev.TabIndex = 1;
            this.Prev.Text = "Prev";
            this.Prev.UseVisualStyleBackColor = true;
            this.Prev.Click += new System.EventHandler(this.Prev_Click);
            // 
            // tagListPanel
            // 
            this.tagListPanel.Controls.Add(this.tagListLabel);
            this.tagListPanel.Location = new System.Drawing.Point(873, 104);
            this.tagListPanel.Name = "tagListPanel";
            this.tagListPanel.Size = new System.Drawing.Size(115, 229);
            this.tagListPanel.TabIndex = 7;
            // 
            // tagListLabel
            // 
            this.tagListLabel.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(55)))), ((int)(((byte)(55)))), ((int)(((byte)(65)))));
            this.tagListLabel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tagListLabel.Font = new System.Drawing.Font("Miriam", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.tagListLabel.ForeColor = System.Drawing.SystemColors.Control;
            this.tagListLabel.Location = new System.Drawing.Point(0, 0);
            this.tagListLabel.Name = "tagListLabel";
            this.tagListLabel.Size = new System.Drawing.Size(115, 229);
            this.tagListLabel.TabIndex = 1;
            this.tagListLabel.Text = "None";
            this.tagListLabel.Visible = false;
            // 
            // userMenu
            // 
            this.userMenu.BackColor = System.Drawing.Color.CornflowerBlue;
            this.userMenu.Dock = System.Windows.Forms.DockStyle.Top;
            this.userMenu.FlatAppearance.BorderSize = 0;
            this.userMenu.FlatAppearance.MouseOverBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(130)))), ((int)(((byte)(179)))), ((int)(((byte)(255)))));
            this.userMenu.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.userMenu.Font = new System.Drawing.Font("Miriam", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.userMenu.ForeColor = System.Drawing.SystemColors.ControlText;
            this.userMenu.Location = new System.Drawing.Point(0, 0);
            this.userMenu.Name = "userMenu";
            this.userMenu.Padding = new System.Windows.Forms.Padding(10, 0, 0, 0);
            this.userMenu.Size = new System.Drawing.Size(239, 42);
            this.userMenu.TabIndex = 18;
            this.userMenu.Text = "User";
            this.userMenu.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.userMenu.UseVisualStyleBackColor = false;
            this.userMenu.Click += new System.EventHandler(this.button1_Click);
            // 
            // userPanel
            // 
            this.userPanel.Controls.Add(this.ListOfUserBTN);
            this.userPanel.Controls.Add(this.RemoveUserBTN);
            this.userPanel.Controls.Add(this.CreateUserBTN);
            this.userPanel.Dock = System.Windows.Forms.DockStyle.Top;
            this.userPanel.Location = new System.Drawing.Point(0, 42);
            this.userPanel.Name = "userPanel";
            this.userPanel.Size = new System.Drawing.Size(239, 111);
            this.userPanel.TabIndex = 19;
            // 
            // ListOfUserBTN
            // 
            this.ListOfUserBTN.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(85)))), ((int)(((byte)(100)))), ((int)(((byte)(120)))));
            this.ListOfUserBTN.Cursor = System.Windows.Forms.Cursors.Hand;
            this.ListOfUserBTN.Dock = System.Windows.Forms.DockStyle.Top;
            this.ListOfUserBTN.FlatAppearance.MouseOverBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(105)))), ((int)(((byte)(120)))), ((int)(((byte)(140)))));
            this.ListOfUserBTN.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.ListOfUserBTN.Font = new System.Drawing.Font("Miriam", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.ListOfUserBTN.Location = new System.Drawing.Point(0, 70);
            this.ListOfUserBTN.Name = "ListOfUserBTN";
            this.ListOfUserBTN.Padding = new System.Windows.Forms.Padding(35, 0, 0, 0);
            this.ListOfUserBTN.Size = new System.Drawing.Size(239, 35);
            this.ListOfUserBTN.TabIndex = 2;
            this.ListOfUserBTN.Text = "List of users";
            this.ListOfUserBTN.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.ListOfUserBTN.UseVisualStyleBackColor = false;
            this.ListOfUserBTN.Click += new System.EventHandler(this.ListOfUsers_Click);
            // 
            // RemoveUserBTN
            // 
            this.RemoveUserBTN.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(85)))), ((int)(((byte)(100)))), ((int)(((byte)(120)))));
            this.RemoveUserBTN.Cursor = System.Windows.Forms.Cursors.Hand;
            this.RemoveUserBTN.Dock = System.Windows.Forms.DockStyle.Top;
            this.RemoveUserBTN.FlatAppearance.MouseOverBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(105)))), ((int)(((byte)(120)))), ((int)(((byte)(140)))));
            this.RemoveUserBTN.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.RemoveUserBTN.Font = new System.Drawing.Font("Miriam", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.RemoveUserBTN.Location = new System.Drawing.Point(0, 37);
            this.RemoveUserBTN.Name = "RemoveUserBTN";
            this.RemoveUserBTN.Padding = new System.Windows.Forms.Padding(35, 0, 0, 0);
            this.RemoveUserBTN.Size = new System.Drawing.Size(239, 33);
            this.RemoveUserBTN.TabIndex = 3;
            this.RemoveUserBTN.Text = "Remove User";
            this.RemoveUserBTN.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.RemoveUserBTN.UseVisualStyleBackColor = false;
            this.RemoveUserBTN.Click += new System.EventHandler(this.RemoveUserBTN_Click);
            // 
            // CreateUserBTN
            // 
            this.CreateUserBTN.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(85)))), ((int)(((byte)(100)))), ((int)(((byte)(120)))));
            this.CreateUserBTN.Cursor = System.Windows.Forms.Cursors.Hand;
            this.CreateUserBTN.Dock = System.Windows.Forms.DockStyle.Top;
            this.CreateUserBTN.FlatAppearance.MouseOverBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(105)))), ((int)(((byte)(120)))), ((int)(((byte)(140)))));
            this.CreateUserBTN.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.CreateUserBTN.Font = new System.Drawing.Font("Miriam", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.CreateUserBTN.Location = new System.Drawing.Point(0, 0);
            this.CreateUserBTN.Name = "CreateUserBTN";
            this.CreateUserBTN.Padding = new System.Windows.Forms.Padding(35, 0, 0, 0);
            this.CreateUserBTN.Size = new System.Drawing.Size(239, 37);
            this.CreateUserBTN.TabIndex = 1;
            this.CreateUserBTN.Text = "Create user";
            this.CreateUserBTN.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.CreateUserBTN.UseVisualStyleBackColor = false;
            this.CreateUserBTN.Click += new System.EventHandler(this.label1_Click);
            // 
            // albumMenu
            // 
            this.albumMenu.BackColor = System.Drawing.Color.CornflowerBlue;
            this.albumMenu.Dock = System.Windows.Forms.DockStyle.Top;
            this.albumMenu.FlatAppearance.BorderSize = 0;
            this.albumMenu.FlatAppearance.MouseOverBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(130)))), ((int)(((byte)(179)))), ((int)(((byte)(255)))));
            this.albumMenu.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.albumMenu.Font = new System.Drawing.Font("Miriam", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.albumMenu.ForeColor = System.Drawing.SystemColors.ControlText;
            this.albumMenu.Location = new System.Drawing.Point(0, 153);
            this.albumMenu.Name = "albumMenu";
            this.albumMenu.Padding = new System.Windows.Forms.Padding(10, 0, 0, 0);
            this.albumMenu.Size = new System.Drawing.Size(239, 42);
            this.albumMenu.TabIndex = 20;
            this.albumMenu.Text = "Albums";
            this.albumMenu.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.albumMenu.UseVisualStyleBackColor = false;
            this.albumMenu.Click += new System.EventHandler(this.albumMenu_Click);
            // 
            // panelAlbum
            // 
            this.panelAlbum.Controls.Add(this.listuseralbumsBTN);
            this.panelAlbum.Controls.Add(this.listalbumsBTN);
            this.panelAlbum.Controls.Add(this.delete_albumBTN);
            this.panelAlbum.Controls.Add(this.closeAlbum);
            this.panelAlbum.Controls.Add(this.open_album);
            this.panelAlbum.Controls.Add(this.CreateALBUM);
            this.panelAlbum.Dock = System.Windows.Forms.DockStyle.Top;
            this.panelAlbum.Location = new System.Drawing.Point(0, 195);
            this.panelAlbum.Name = "panelAlbum";
            this.panelAlbum.Size = new System.Drawing.Size(239, 210);
            this.panelAlbum.TabIndex = 21;
            // 
            // listuseralbumsBTN
            // 
            this.listuseralbumsBTN.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(85)))), ((int)(((byte)(100)))), ((int)(((byte)(120)))));
            this.listuseralbumsBTN.Cursor = System.Windows.Forms.Cursors.Hand;
            this.listuseralbumsBTN.Dock = System.Windows.Forms.DockStyle.Top;
            this.listuseralbumsBTN.FlatAppearance.MouseOverBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(105)))), ((int)(((byte)(120)))), ((int)(((byte)(140)))));
            this.listuseralbumsBTN.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.listuseralbumsBTN.Font = new System.Drawing.Font("Miriam", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.listuseralbumsBTN.Location = new System.Drawing.Point(0, 175);
            this.listuseralbumsBTN.Name = "listuseralbumsBTN";
            this.listuseralbumsBTN.Padding = new System.Windows.Forms.Padding(35, 0, 0, 0);
            this.listuseralbumsBTN.Size = new System.Drawing.Size(239, 35);
            this.listuseralbumsBTN.TabIndex = 6;
            this.listuseralbumsBTN.Text = "List user albums";
            this.listuseralbumsBTN.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.listuseralbumsBTN.UseVisualStyleBackColor = false;
            this.listuseralbumsBTN.Click += new System.EventHandler(this.listuseralbumsBTN_Click);
            // 
            // listalbumsBTN
            // 
            this.listalbumsBTN.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(85)))), ((int)(((byte)(100)))), ((int)(((byte)(120)))));
            this.listalbumsBTN.Cursor = System.Windows.Forms.Cursors.Hand;
            this.listalbumsBTN.Dock = System.Windows.Forms.DockStyle.Top;
            this.listalbumsBTN.FlatAppearance.MouseOverBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(105)))), ((int)(((byte)(120)))), ((int)(((byte)(140)))));
            this.listalbumsBTN.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.listalbumsBTN.Font = new System.Drawing.Font("Miriam", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.listalbumsBTN.Location = new System.Drawing.Point(0, 140);
            this.listalbumsBTN.Name = "listalbumsBTN";
            this.listalbumsBTN.Padding = new System.Windows.Forms.Padding(35, 0, 0, 0);
            this.listalbumsBTN.Size = new System.Drawing.Size(239, 35);
            this.listalbumsBTN.TabIndex = 5;
            this.listalbumsBTN.Text = "List albums";
            this.listalbumsBTN.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.listalbumsBTN.UseVisualStyleBackColor = false;
            this.listalbumsBTN.Click += new System.EventHandler(this.listalbumsBTN_Click);
            // 
            // delete_albumBTN
            // 
            this.delete_albumBTN.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(85)))), ((int)(((byte)(100)))), ((int)(((byte)(120)))));
            this.delete_albumBTN.Cursor = System.Windows.Forms.Cursors.Hand;
            this.delete_albumBTN.Dock = System.Windows.Forms.DockStyle.Top;
            this.delete_albumBTN.FlatAppearance.MouseOverBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(105)))), ((int)(((byte)(120)))), ((int)(((byte)(140)))));
            this.delete_albumBTN.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.delete_albumBTN.Font = new System.Drawing.Font("Miriam", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.delete_albumBTN.Location = new System.Drawing.Point(0, 105);
            this.delete_albumBTN.Name = "delete_albumBTN";
            this.delete_albumBTN.Padding = new System.Windows.Forms.Padding(35, 0, 0, 0);
            this.delete_albumBTN.Size = new System.Drawing.Size(239, 35);
            this.delete_albumBTN.TabIndex = 4;
            this.delete_albumBTN.Text = "Delete album";
            this.delete_albumBTN.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.delete_albumBTN.UseVisualStyleBackColor = false;
            this.delete_albumBTN.Click += new System.EventHandler(this.delete_albumBTN_Click);
            // 
            // closeAlbum
            // 
            this.closeAlbum.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(85)))), ((int)(((byte)(100)))), ((int)(((byte)(120)))));
            this.closeAlbum.Cursor = System.Windows.Forms.Cursors.Hand;
            this.closeAlbum.Dock = System.Windows.Forms.DockStyle.Top;
            this.closeAlbum.FlatAppearance.MouseOverBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(105)))), ((int)(((byte)(120)))), ((int)(((byte)(140)))));
            this.closeAlbum.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.closeAlbum.Font = new System.Drawing.Font("Miriam", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.closeAlbum.Location = new System.Drawing.Point(0, 70);
            this.closeAlbum.Name = "closeAlbum";
            this.closeAlbum.Padding = new System.Windows.Forms.Padding(35, 0, 0, 0);
            this.closeAlbum.Size = new System.Drawing.Size(239, 35);
            this.closeAlbum.TabIndex = 2;
            this.closeAlbum.Text = "Close album";
            this.closeAlbum.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.closeAlbum.UseVisualStyleBackColor = false;
            this.closeAlbum.Click += new System.EventHandler(this.closeAlbumBTN_Click);
            // 
            // open_album
            // 
            this.open_album.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(85)))), ((int)(((byte)(100)))), ((int)(((byte)(120)))));
            this.open_album.Cursor = System.Windows.Forms.Cursors.Hand;
            this.open_album.Dock = System.Windows.Forms.DockStyle.Top;
            this.open_album.FlatAppearance.MouseOverBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(105)))), ((int)(((byte)(120)))), ((int)(((byte)(140)))));
            this.open_album.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.open_album.Font = new System.Drawing.Font("Miriam", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.open_album.Location = new System.Drawing.Point(0, 37);
            this.open_album.Name = "open_album";
            this.open_album.Padding = new System.Windows.Forms.Padding(35, 0, 0, 0);
            this.open_album.Size = new System.Drawing.Size(239, 33);
            this.open_album.TabIndex = 3;
            this.open_album.Text = "Open album";
            this.open_album.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.open_album.UseVisualStyleBackColor = false;
            this.open_album.Click += new System.EventHandler(this.open_album_Click);
            // 
            // CreateALBUM
            // 
            this.CreateALBUM.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(85)))), ((int)(((byte)(100)))), ((int)(((byte)(120)))));
            this.CreateALBUM.Cursor = System.Windows.Forms.Cursors.Hand;
            this.CreateALBUM.Dock = System.Windows.Forms.DockStyle.Top;
            this.CreateALBUM.FlatAppearance.MouseOverBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(105)))), ((int)(((byte)(120)))), ((int)(((byte)(140)))));
            this.CreateALBUM.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.CreateALBUM.Font = new System.Drawing.Font("Miriam", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.CreateALBUM.Location = new System.Drawing.Point(0, 0);
            this.CreateALBUM.Name = "CreateALBUM";
            this.CreateALBUM.Padding = new System.Windows.Forms.Padding(35, 0, 0, 0);
            this.CreateALBUM.Size = new System.Drawing.Size(239, 37);
            this.CreateALBUM.TabIndex = 1;
            this.CreateALBUM.Text = "Create album";
            this.CreateALBUM.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.CreateALBUM.UseVisualStyleBackColor = false;
            this.CreateALBUM.Click += new System.EventHandler(this.createAlbumBTN);
            // 
            // picMenu
            // 
            this.picMenu.BackColor = System.Drawing.Color.CornflowerBlue;
            this.picMenu.Dock = System.Windows.Forms.DockStyle.Top;
            this.picMenu.FlatAppearance.BorderSize = 0;
            this.picMenu.FlatAppearance.MouseOverBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(130)))), ((int)(((byte)(179)))), ((int)(((byte)(255)))));
            this.picMenu.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.picMenu.Font = new System.Drawing.Font("Miriam", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.picMenu.ForeColor = System.Drawing.SystemColors.ControlText;
            this.picMenu.Location = new System.Drawing.Point(0, 405);
            this.picMenu.Name = "picMenu";
            this.picMenu.Padding = new System.Windows.Forms.Padding(10, 0, 0, 0);
            this.picMenu.Size = new System.Drawing.Size(239, 42);
            this.picMenu.TabIndex = 22;
            this.picMenu.Text = "Pictures";
            this.picMenu.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.picMenu.UseVisualStyleBackColor = false;
            this.picMenu.Click += new System.EventHandler(this.picMenu_Click);
            // 
            // picPanel
            // 
            this.picPanel.Controls.Add(this.listPictures);
            this.picPanel.Controls.Add(this.RemovePicBTN);
            this.picPanel.Controls.Add(this.addPicBTN);
            this.picPanel.Dock = System.Windows.Forms.DockStyle.Top;
            this.picPanel.Location = new System.Drawing.Point(0, 447);
            this.picPanel.Name = "picPanel";
            this.picPanel.Size = new System.Drawing.Size(239, 111);
            this.picPanel.TabIndex = 23;
            // 
            // listPictures
            // 
            this.listPictures.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(85)))), ((int)(((byte)(100)))), ((int)(((byte)(120)))));
            this.listPictures.Cursor = System.Windows.Forms.Cursors.Hand;
            this.listPictures.Dock = System.Windows.Forms.DockStyle.Top;
            this.listPictures.FlatAppearance.MouseOverBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(105)))), ((int)(((byte)(120)))), ((int)(((byte)(140)))));
            this.listPictures.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.listPictures.Font = new System.Drawing.Font("Miriam", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.listPictures.Location = new System.Drawing.Point(0, 70);
            this.listPictures.Name = "listPictures";
            this.listPictures.Padding = new System.Windows.Forms.Padding(35, 0, 0, 0);
            this.listPictures.Size = new System.Drawing.Size(239, 35);
            this.listPictures.TabIndex = 2;
            this.listPictures.Text = "Show Pictures";
            this.listPictures.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.listPictures.UseVisualStyleBackColor = false;
            this.listPictures.Click += new System.EventHandler(this.listPictures_Click);
            // 
            // RemovePicBTN
            // 
            this.RemovePicBTN.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(85)))), ((int)(((byte)(100)))), ((int)(((byte)(120)))));
            this.RemovePicBTN.Cursor = System.Windows.Forms.Cursors.Hand;
            this.RemovePicBTN.Dock = System.Windows.Forms.DockStyle.Top;
            this.RemovePicBTN.FlatAppearance.MouseOverBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(105)))), ((int)(((byte)(120)))), ((int)(((byte)(140)))));
            this.RemovePicBTN.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.RemovePicBTN.Font = new System.Drawing.Font("Miriam", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.RemovePicBTN.Location = new System.Drawing.Point(0, 37);
            this.RemovePicBTN.Name = "RemovePicBTN";
            this.RemovePicBTN.Padding = new System.Windows.Forms.Padding(35, 0, 0, 0);
            this.RemovePicBTN.Size = new System.Drawing.Size(239, 33);
            this.RemovePicBTN.TabIndex = 3;
            this.RemovePicBTN.Text = "Remove picture";
            this.RemovePicBTN.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.RemovePicBTN.UseVisualStyleBackColor = false;
            this.RemovePicBTN.Click += new System.EventHandler(this.RemovePicBTN_Click);
            // 
            // addPicBTN
            // 
            this.addPicBTN.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(85)))), ((int)(((byte)(100)))), ((int)(((byte)(120)))));
            this.addPicBTN.Cursor = System.Windows.Forms.Cursors.Hand;
            this.addPicBTN.Dock = System.Windows.Forms.DockStyle.Top;
            this.addPicBTN.FlatAppearance.MouseOverBackColor = System.Drawing.Color.FromArgb(((int)(((byte)(105)))), ((int)(((byte)(120)))), ((int)(((byte)(140)))));
            this.addPicBTN.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.addPicBTN.Font = new System.Drawing.Font("Miriam", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.addPicBTN.Location = new System.Drawing.Point(0, 0);
            this.addPicBTN.Name = "addPicBTN";
            this.addPicBTN.Padding = new System.Windows.Forms.Padding(35, 0, 0, 0);
            this.addPicBTN.Size = new System.Drawing.Size(239, 37);
            this.addPicBTN.TabIndex = 1;
            this.addPicBTN.Text = "Add Picture";
            this.addPicBTN.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            this.addPicBTN.UseVisualStyleBackColor = false;
            this.addPicBTN.Click += new System.EventHandler(this.addPicBTN_Click);
            // 
            // GalleryGUI
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(52)))), ((int)(((byte)(53)))), ((int)(((byte)(65)))));
            this.ClientSize = new System.Drawing.Size(1131, 654);
            this.Controls.Add(this.tagListPanel);
            this.Controls.Add(this.imageListPanel);
            this.Controls.Add(this.currAlbumLabel);
            this.Controls.Add(this.AlbumPanel);
            this.Controls.Add(this.DataShow);
            this.Controls.Add(this.EntryPANEL);
            this.Controls.Add(this.SideBar);
            this.Name = "GalleryGUI";
            this.Text = "GalleryGUI";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.SideBar.ResumeLayout(false);
            this.SideBar.PerformLayout();
            this.EntryPANEL.ResumeLayout(false);
            this.EntryPANEL.PerformLayout();
            this.DataShow.ResumeLayout(false);
            this.AlbumPanel.ResumeLayout(false);
            this.AlbumPanel.PerformLayout();
            this.imageListPanel.ResumeLayout(false);
            this.TagPanel.ResumeLayout(false);
            this.TagPanel.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.tagListPanel.ResumeLayout(false);
            this.userPanel.ResumeLayout(false);
            this.panelAlbum.ResumeLayout(false);
            this.picPanel.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Panel SideBar;
        private System.Windows.Forms.TextBox userENTRY;
        private System.Windows.Forms.Button AcceptBTN;
        private System.Windows.Forms.Panel EntryPANEL;
        private System.Windows.Forms.Label UserName;
        private System.Windows.Forms.Panel DataShow;
        private System.Windows.Forms.Label DataLabel;
        private System.Windows.Forms.Button Close;
        private System.Windows.Forms.Panel AlbumPanel;
        private System.Windows.Forms.Label AlbumEntry2;
        private System.Windows.Forms.Label AlbumEntry1;
        private System.Windows.Forms.TextBox albumtxt2;
        private System.Windows.Forms.TextBox albumtxt1;
        private System.Windows.Forms.Button albumEnter;
        private System.Windows.Forms.Label currAlbumLabel;
        private System.Windows.Forms.Button TagUserBTN;
        private System.Windows.Forms.Button ListTagsBTN;
        private System.Windows.Forms.Button button6;
        private System.Windows.Forms.Panel imageListPanel;
        private System.Windows.Forms.Button Next;
        private System.Windows.Forms.Button Prev;
        private System.Windows.Forms.Button CloseImage;
        private System.Windows.Forms.Panel TagPanel;
        private System.Windows.Forms.Label taguserLabel;
        private System.Windows.Forms.Button aceeptTAG;
        private System.Windows.Forms.TextBox tagBox;
        private System.Windows.Forms.Panel tagListPanel;
        private System.Windows.Forms.Label tagListLabel;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.Label GalleryLAbel;
        private System.Windows.Forms.Panel picPanel;
        private System.Windows.Forms.Button listPictures;
        private System.Windows.Forms.Button RemovePicBTN;
        private System.Windows.Forms.Button addPicBTN;
        private System.Windows.Forms.Button picMenu;
        private System.Windows.Forms.Panel panelAlbum;
        private System.Windows.Forms.Button listuseralbumsBTN;
        private System.Windows.Forms.Button listalbumsBTN;
        private System.Windows.Forms.Button delete_albumBTN;
        private System.Windows.Forms.Button closeAlbum;
        private System.Windows.Forms.Button open_album;
        private System.Windows.Forms.Button CreateALBUM;
        private System.Windows.Forms.Button albumMenu;
        private System.Windows.Forms.Panel userPanel;
        private System.Windows.Forms.Button ListOfUserBTN;
        private System.Windows.Forms.Button RemoveUserBTN;
        private System.Windows.Forms.Button CreateUserBTN;
        private System.Windows.Forms.Button userMenu;
    }
}

