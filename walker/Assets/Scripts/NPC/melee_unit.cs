using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;

public class melee_unit : unit
{
    // Start is called before the first frame update
    protected override void Start()
    {
        base.Start();
    }
    public override void activation()
    {
        GetComponentInChildren<BoxCollider2D>().enabled = true;
    }
    // Update is called once per frame
    void Update()
    {
        
    }
}
